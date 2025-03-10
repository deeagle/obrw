/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_utils.h
 *
 * \brief The file includes some methods which work like utils for the tool
 * OBRW. So you may find some methods to get random-digits, or a version of free
 * with some security options.
 */
#ifndef OBRW_UTILS_H
#define OBRW_UTILS_H

#include <stdlib.h>
#include <time.h>

#include "obrw_logger.h"

/**
 * Local var describes the multiplier for random digits. For example:
 * if it's 10.0 the max count is 10 - 1 = 9;
 */
static double DIGIT_BORDER_HIGH;

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
 * Get the users home-path.
 *
 * \returns The users-home-path (set in the environment).
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
void obrwUtils_freeCString(char **);

#endif  // OBRW_UTILS_H
