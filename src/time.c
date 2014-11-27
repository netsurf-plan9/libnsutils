/*
 * Copyright 2014 Vincent Sanders <vince@netsurf-browser.org>
 *
 * This file is part of libnsutils.
 *
 * Licensed under the MIT License,
 *                http://www.opensource.org/licenses/mit-license.php
 */

/**
 * \file
 * Time operation implementation
 */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "nsutils/time.h"

/* exported interface documented in nsutils/time.h */
nsuerror nsu_getmonotonic_ms(uint64_t *current_out)
{
    uint64_t current;
    static uint64_t prev = 0; /* previous time so we never go backwards */

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0) && (defined _POSIX_MONOTONIC_CLOCK)
#include <time.h>
    struct timespec tp;

    clock_gettime(CLOCK_MONOTONIC, &tp);
    current = (tp.tv_sec * 1000) + (tp.tv_nsec / 1000000);
#elif defined(riscos)
#include "oslib/os.h"
    os_t time;

    time = os_read_monotonic_time();
    current = time * 10;
#else
#warning "Using dodgy gettimeofday() fallback"
#include <sys/time.h>
    /** \todo Implement this properly! */
    struct timeval tv;

    gettimeofday(&tv, NULL);

    current = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
#endif

    /* ensure time never goes backwards */
    if (current > prev) {
        *current_out = current;
        prev = current;
    } else {
        /** \todo is 10ms really correct or can we calculate a delta going forwards? */
        prev += 10;
        *current_out = prev;
    }
    return NSUERROR_OK;
}
