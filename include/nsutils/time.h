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
 * Base64 encoding and decoding interface.
 */

#ifndef NSUTILS_TIME_H_
#define NSUTILS_TIME_H_

#include <nsutils/errors.h>

/**
 * Get a monotonically incriminating number of milliseconds.
 *
 * Obtain a count of elapsed time in milliseconds from an arbitrary point in
 * time. Unlike gettimeofday this will continue linearly across time setting
 * and not go backwards.
 *
 * \note The read value will always increment by at least 1 on each call meaning
 * times less than 1ms cannot be differentiated.
 *
 * \param current The current value of the counter.
 * \return NSERROR_OK on success else error code.
 */
nsuerror nsu_getmonotonic_ms(uint64_t *current);
 
#endif
