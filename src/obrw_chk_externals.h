/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_chk_externals.h
 *
 * \brief The file includes the definitions of functions which checks, if needed
 * external dependencies are available.
 */
#ifndef OBRW_CHK_EXTERNALS_H
#define OBRW_CHK_EXTERNALS_H

#include <sys/stat.h>  /* LINUX / UNIX */
#include <sys/types.h> /* LINUX / UNIX */

#ifdef __unix__

#include <unistd.h>

// redefine access tokens
#define EXIST F_OK
#define EXEC X_OK
#define WRITE W_OK
#define READ R_OK
// define calls and returns
#define EXIST_OK 0
#define EXEC_OK 0
#define FEH_EXIST_AND_EXEC 0
#define FEH_NOT_EXEC 1
#define FEH_NOT_EXIST (-1)
#endif

/**
 * The function checks if extern tool 'feh' is installed (bin at /usr/bin/feh).
 *
 * \return The function returns FEH_EXIST_AND_EXEC if feh is installed (bin at /usr/bin/feh) and
 * FEH_NOT_EXIST if it's not installed.
 *
 * \retval FEH_EXIST_AND_EXEC
 * \retval FEH_NOT_EXEC
 * \retval FEH_NOT_EXIST
 */
int obrwChkExt_isFehOnSystem(void);

#endif  // OBRW_CHK_EXTERNALS_H
