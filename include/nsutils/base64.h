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

#ifndef NSUTILS_BASE64_H_
#define NSUTILS_BASE64_H_

#include <nsutils/errors.h>

nserror nsu_base64_encode_alloc(const uint8_t *input,
                            size_t input_length,
                            uint8_t **output,
                            size_t *output_length);

nserror nsu_base64_decode_alloc(const uint8_t *input,
                            size_t input_length,
                            uint8_t **output,
                            size_t *output_length);
 
#endif
