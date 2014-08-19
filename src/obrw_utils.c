/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_utils.c
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
 * \file obrw_utils.c
 *
 * \brief The file includes some methods which work like utils for the tool OBRW.
 * So you may find some methods to get random-digits, or a version of free with some security options.
 *
 */

#include "obrw_utils.h"


/** Local multiplikator for random digits */
static double DIGIT_BORDER_HIGH = 10.0;


/** Set's the local multiplikator for random digits. */
void
obrwUtils_setHighDigitBorder( double highBorder )
{
	DIGIT_BORDER_HIGH = highBorder;
}//obrwUtils_setHighDigitBorder( double )


/** Resets and start the random-number-couter. */
void
obrwUtils_setRandomCounterToZero( void )
{
	srand( time( NULL ) * time( NULL ) );
}//obrwUtils_setRandomCounterToZero()


/** Get a random number. */
int
obrwUtils_randomDigit( void )
{
	return ( (int) ( (double) rand() / ( (double) ( RAND_MAX ) ) * DIGIT_BORDER_HIGH ) );
}//obrwUtils_randomDigit()


/** Get the users home path. */
char*
obrwUtils_getUserHomeDir( void )
{
	return getenv( "HOME" );
}//obrwUtils_getUserHomeDir()


/** OBRW Version of free(). */
void
obrwUtils_freeCString( char* cstr )
{
	if( cstr != NULL )
	{
		//TODO
		//valgrinderror ?
		//memset( cstr, '0', strlen( cstr ) );
		free( cstr );
		cstr = NULL;
	}//if
}//obrwUtils_freeCString( char* )
