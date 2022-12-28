/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_chk_externals.c
 *
 * \brief The file includes the definitions of functions which checks, if needed
 * external dependencies are available.
 */
#include "obrw_chk_externals.h"

/**
 * Returns the stage of the default installation setup of external tool <<feh>>.
 * <p>
 * Checks if the tool is installed at /usr/bin/feh (binary) and is executable.
 */
int obrwChkExt_isFehOnSystem(void) {
    const char *fehPath = "/usr/bin/feh\0";

    if (access(fehPath, EXIST) != EXIST) {
        return FEH_NOT_EXIST;
    }

    if (access(fehPath, EXEC) != EXEC) {
        return FEH_NOT_EXEC;
    }

    return FEH_EXIST_AND_EXEC;
}
