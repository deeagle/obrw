/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_string.c
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
 * \file obrw_string.c
 *
 * \brief The file includes the special cstring-methods for the tool obrw.
 *
 */

#include "obrw_string.h"


/** Concatenates two cstrings to one cstring. */
char*
obrwString_2CStringsTo1( const char* str1, const char* str2 )
{
	size_t len = 0;
	char* ptr = NULL;

	if( str1 != NULL && str2 != NULL )
	{
		len = strlen( str1 ) + strlen( str2 ) + 1;
		ptr = (char*) malloc( sizeof( char ) * len );

		// check if ptr exist because malloc allocs on heap-space
		// and it can fail.
		if( ptr )
		{
		  	strncpy( ptr, str1, strlen( str1 ) + 1 );
			strncat( ptr, str2, strlen( str2 ) + 1 );
		}//if
	}//if

	return ptr;
}//obrwString_2to1( const char*, const char* )


/** Parses cstrings and extract chars between "". */
char*
obrwString_parseConfigFileFor( const char* line )
{
	char *parsedStr = NULL;
	char *strPtr = NULL;
	size_t len = 0;

	if( line != NULL )
	{
		// find the first " (DEZ = 34) in the cstring, 
		// do a copy and deletes the second " at the end of the line.
		if( ( strPtr = strchr( line, (int) '"' ) ) != NULL )
		{
			len = strlen( strPtr );
			parsedStr = (char*) malloc( sizeof( char ) * len );
			
			strPtr++;
			if( parsedStr )
			{
				strncpy( parsedStr, strPtr, ( strlen( strPtr ) - 1 ) );

				if( 0 < OBRW_GLOBAL_DEBUG )
				{
					//FIXME
					printf( "[DBG] ParsedStr is >> %s <<\n", parsedStr );
				}//if
			}//if
			else
			{
				printf( "[ERR] No memory (heap) avaiable!\n" );
				//return NULL;
			}//else
		}//if
		else
		{
			printf( "[ERR] Error parsing %s (Return NULL ).\n", line );
			//return NULL;
		}//else
	}//if

	return parsedStr;
}//obrwString_parseConfigFileFor( const char* )
