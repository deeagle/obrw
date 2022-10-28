/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_utils.c
 *
 * \brief The file includes some methods which work like utils for the tool
 * OBRW. So you may find some methods to get random-digits, or a version of free
 * with some security options.
 */
#include "obrw_utils.h"

/** Local multiplier for random digits */
static double DIGIT_BORDER_HIGH = 10.0;

/** Resets and start the random-number-counter. */
void obrwUtils_setRandomCounterToZero(void) {
    srand(time(NULL) * time(NULL));
}

/** Get a random number. */
int obrwUtils_randomDigit(void) {
    return ((int) ((double) rand() / ((double) (RAND_MAX)) * DIGIT_BORDER_HIGH));
}

/** Get the users home path. */
char *obrwUtils_getUserHomeDir(void) {
    return getenv("HOME");
}

/** OBRW Version of free(). */
void obrwUtils_freeCString(char *cstr) {
    if (cstr != NULL) {
        char *logMsg = (char *) malloc((16 + strlen(cstr)) * sizeof(char));
        sprintf(logMsg, "free string <%s>.", cstr);
        obrwLogger_debugSystem(logMsg);

        // TODO
        // valgrind-error ?
        // memset( cstr, '0', strlen( cstr ) );
        free(logMsg);
        free(cstr);

        // free:
        // - it marks the memory as free, that means the value can still exist!
        // - so I set it manually to NULL.
        cstr = NULL;
    }
}
