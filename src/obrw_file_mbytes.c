/*
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_file_mbytes.c
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
 * It is provided "as is" without express or implied warranty.
 *
 */

#include "obrw_file_mbytes.h"

void obrwFileMBytes_fileFormatInit() {
  if (2 < OBRW_GLOBAL_DEBUG) {
    obrwLogger_debug("Init file-format jfif.");
  }
  // init jfif
  jfif.b0 = 0xFF;
  jfif.b1 = 0xD8;
  jfif.b2 = 0xFF;
}
