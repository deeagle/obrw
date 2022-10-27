/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_utils.h
 *
 * URL: http://deeagle.de
 *
 * Copyright (c) 2007-2010 Martin Kock <root@deeagle.de>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.\n\n\n
 *
 *
 * \file obrw_utils.h
 *
 * \brief The file includes some methods which work like utils for the tool
 * OBRW. So you may find some methods to get random-digits, or a version of free
 * with some security options.
 *
 */

#ifndef OBRW_UTILS_H
#define OBRW_UTILS_H

#include <stdlib.h>
#include <time.h>

#include "obrw_logger.h"

/**
 * Local var describes the multiplikator for random digits. For example:
 * if it's 10.0 the max count is 10 - 1 = 9;
 */
static double DIGIT_BORDER_HIGH;

/**
 * Set's the local multiplikator for random digits.
 *
 * \returns Nothing, it's void.
 */
void obrwUtils_setHighDigitBorder(double);

/**
 * Resets and starts the random-number-generator.
 *
 * \returns Nothing, it's void.
 */
void obrwUtils_setRandomCounterToZero(void);

/**
 * Get a random number (remember to start counter before get a random).
 *
 * \returns A random number as an integer.
 */
int obrwUtils_randomDigit(void);

/**
 * Get the users homepath.
 *
 * \returns The users-homepath (set in the environment).
 * \retval /home/user/ success.
 * \retval NULL fail.
 */
char *obrwUtils_getUserHomeDir(void);

/**
 * OBRW-Version of free(). It's a four-way-working-function:\n
 * 1. Check if it's exist.\n
 * 2. Rewrite old data with 0.\n
 * 3. Free data.\n
 * 4. set ptr NULL.\n
 *
 * \returns Nothing, it's void.
 */
void obrwUtils_freeCString(char *);

#endif  // OBRW_UTILS_H
