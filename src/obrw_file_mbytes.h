/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_chk_externals.h
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_file_mbytes.h
 */
#ifndef OBRW_FILE_MBYTES_H
#define OBRW_FILE_MBYTES_H
#define BYTE unsigned char

#include "obrw_logger.h"

struct obrwFileMBytes_fileFormat {
    BYTE b0;
    BYTE b1;
    BYTE b2;
} jfif;

void obrwFileMBytes_fileFormatInit();

#endif  // OBRW_MBYTES_H
