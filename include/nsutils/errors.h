/*
 * Copyright 2014 John-Mark Bell <jmb@netsurf-browser.org>
 *
 * This file is part of libnsutils.
 *
 * Licensed under the MIT License,
 *                http://www.opensource.org/licenses/mit-license.php
 */

/**
 * \file
 * Error codes.
 */

#ifndef NSUTILS_ERRORS_H_
#define NSUTILS_ERRORS_H_

/**
 * Enumeration of error codes
 */
typedef enum {
	NSERROR_OK,			/**< No error */

	NSERROR_UNKNOWN,		/**< Unknown error - DO *NOT* USE */

	NSERROR_NOMEM,			/**< Memory exhaustion */

	NSERROR_NO_FETCH_HANDLER,	/**< No fetch handler for URL scheme */

	NSERROR_NOT_FOUND,		/**< Requested item not found */

	NSERROR_NOT_DIRECTORY,           /**< Missing directory */

	NSERROR_SAVE_FAILED,		/**< Failed to save data */

	NSERROR_CLONE_FAILED,		/**< Failed to clone handle */

	NSERROR_INIT_FAILED,		/**< Initialisation failed */

	NSERROR_MNG_ERROR,		/**< An MNG error occurred */

	NSERROR_BAD_ENCODING,		/**< The character set is unknown */

	NSERROR_NEED_DATA,		/**< More data needed */

	NSERROR_ENCODING_CHANGE,	/**< The character changed */

	NSERROR_BAD_PARAMETER,		/**< Bad Parameter */

	NSERROR_INVALID,		/**< Invalid data */

	NSERROR_BOX_CONVERT,		/**< Box conversion failed */

	NSERROR_STOPPED,		/**< Content conversion stopped */

	NSERROR_DOM,	                /**< DOM call returned error */

	NSERROR_CSS,	                /**< CSS call returned error */

	NSERROR_CSS_BASE,               /**< CSS base sheet failed */

	NSERROR_BAD_URL,		/**< Bad URL */

	NSERROR_BAD_CONTENT,		/**< Bad Content */

	NSERROR_FRAME_DEPTH,            /**< Exceeded frame depth */

	NSERROR_PERMISSION,             /**< Permission error */

	NSERROR_NOSPACE,		/**< Insufficient space */

	NSERROR_BAD_SIZE,               /**< Bad size */

	NSERROR_NOT_IMPLEMENTED,        /**< Functionality is not implemented */
} nserror;

#endif

