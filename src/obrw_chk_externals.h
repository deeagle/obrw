/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_chk_externals.h
 *
 * URL: http://deeagle.de
 *
 * Copyright (c) 2007-2010 Martin Kock <code@deeagle.de>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.\n\n\n
 *
 *
 * \file obrw_chk_externals.h
 *
 * \brief The file includes the definitons of functions which checks, if needed
 * external dependencies are avaiable.
 *
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

#endif  // OBRW_EXT_EXTERNALS_H
