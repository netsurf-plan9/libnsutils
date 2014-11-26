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
#include <sys/time.h>
#include <time.h>

#include "nsutils/time.h"

/* exported interface documented in nsutils/time.h */
nsuerror nsu_getmonotonic_ms(uint64_t *current)
{
#if (_POSIX_TIMERS > 0) && (defined _POSIX_MONOTONIC_CLOCK)
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    *current = (tp.tv_sec * 1000) + (tp.tv_nsec / 1000000);
#else
#warning "Using dodgy gettimeofday() fallback"
    /** \todo Implement this properly! */
    struct timeval tv;

    gettimeofday(&tv, NULL);

    *current = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
#endif
    return NSUERROR_OK;
}
