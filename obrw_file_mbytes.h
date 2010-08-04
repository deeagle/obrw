/*
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_file_mbytes.h
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
 *
 * \file obrw_file_mbytes.h
 */

#ifndef OBRW_FILE_MBYTES_H
#define OBRW_FILE_MBYTES_H
#define BYTE unsigned char

#include "obrw_globals.h"

struct obrwFileMBytes_fileFormat
{
	BYTE b0;
	BYTE b1;
	BYTE b2;
}jfif;

void obrwFileMBytes_fileFormatInit();

#endif //OBRW_MBYTES_H
