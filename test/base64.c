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
 *
 * Base64 test program. Reads data from stdin and en/de codes it to/from base64
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <nsutils/base64.h>

int main(int argc, char**argv)
{
    uint8_t *buffer;
    size_t buffer_len;
    uint8_t *output;
    size_t output_len;

    if (scanf("%1024mc%n", &buffer, (int *)&buffer_len) < 1) {
        return 1;
    }
    
    if (argc == 1) {
        /* encode */
        base64_encode_alloc(buffer, buffer_len, &output, &output_len);
    } else {
        /* decode */
        base64_decode_alloc(buffer, buffer_len, &output, &output_len);
    }

    if (output != NULL) {
        printf("%.*s", (int)output_len, output);
        free(output);
    }

    free(buffer);
    
}
