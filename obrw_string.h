/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_string.h
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
 * It is provided "as is" without express or implied warranty.\n\n\n
 *
 *
 * \file obrw_string.h
 *
 * \brief The file includes the special cstring-methods for the tool obrw.
 *
 */

#ifndef OBRW_STRING_H
#define OBRW_STRING_H

#include <string.h>
#include <stdio.h>
#include "obrw_globals.h"


/** 
 * Concatenates two cstrings to one cstring.
 *
 * \returns The concatenate cstring with termination '\\0'.
 * \retval char* success.
 * \retval NULL fail.
 */
char* obrwString_2CStringsTo1( const char*, const char* );

/** 
 * Pareses cstrings and extract chars between "" with termination '\\0'. For example:\n
 * in:	tag = "the needed information"\n
 * out:	the needed information\n.
 *
 * \returns The parsed cstring with the needed information.
 * \retval char* success.
 * \retval NULL fail.
 */
char* obrwString_parseConfigFileFor( const char* );


#endif //OBRW_STRING_H
