/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_chk_externals.h
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_file_mbytes.c
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
