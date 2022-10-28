/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_chk_externals.c
 *
 * \brief The file includes the definitons of functions which checks, if needed
 * external dependencies are avaiable.
 */
#include "obrw_chk_externals.h"

/** The function checks if extern tool 'feh' is installed (bin at /usr/bin/feh).
 */
int obrwChkExt_isFehOnSystem(void) {
    int fehIsInstalled = 0;

    //* searching /usr/bin/feh
    const char *fehPath = "/usr/bin/feh\0";

    //* feh exists?
    if (access(fehPath, EXIST) != -1) {
        if (access(fehPath, EXEC) != -1) {
            fehIsInstalled = 1;
        }
    }

    return fehIsInstalled;
}
