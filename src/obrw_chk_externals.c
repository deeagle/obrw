/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_chk_externals.c
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
 * \file obrw_chk_externals.c
 *
 * \brief The file includes the definitons of functions which checks, if needed
 * external dependencies are avaiable.
 *
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
    } // if
  }   // if

  return fehIsInstalled;
} // obrwChkExt_isFehOnSystem()
