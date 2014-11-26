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
#include <sys/time.h>

#include "nsutils/time.h"

/* exported interface documented in nsutils/time.h */
nsuerror nsu_nsu_getmonotonic_ms(uint64_t *current)
{
    /** \todo Implement this properly! */
    struct timeval tv;

    gettimeofday(&tv, NULL);

    *current = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);

    return NSUERROR_OK;
}
