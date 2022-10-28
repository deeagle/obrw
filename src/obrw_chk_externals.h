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

#define EXIST F_OK
#define EXEC X_OK
#define WRITE W_OK
#define READ R_OK
#endif

/**
 * The function checks if extern tool 'feh' is installed (bin at /usr/bin/feh).
 *
 * \return The function returns 1 if feh is installed (bin at /usr/bin/feh) and
 * 0 if it's not installed. \retval 1 true \retval 0 false
 */
int obrwChkExt_isFehOnSystem(void);

#endif  // OBRW_CHK_EXTERNALS_H
