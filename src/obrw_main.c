/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_main.c
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
 * \file obrw_main.c
 *
 * \brief The file includes the main-method of the tool obrw. Also there is an method to free all used alocated variables.
 *
 */

#include "obrw_main.h"


/** The main-method, which starts the obrw-process. */
int
main()
{
	obrwUtils_setRandomCounterToZero();

	if( 0 < OBRW_GLOBAL_DEBUG )
	{
        char *logMsg = (char*)malloc(20 * sizeof(char));
        sprintf( logMsg, "Debug-Lvl is %d.", OBRW_GLOBAL_DEBUG);
        obrwLogger_info( logMsg );
        obrwUtils_freeCString( logMsg );
	}//if

	if( obrwChkExt_isFehOnSystem() == 0 )
	{
		freeAllToClose();
		obrwLogger_error("Feh is not installed!");
		return EXIT_FAILURE;
	}//if

	if( obrwConfig_readConfigFile() /* == EXIT_FAILURE */)
	{
		freeAllToClose();
		obrwLogger_error("Found error in obrw.conf!");
		return EXIT_FAILURE;
	}//if

	if( obrwWallpaperOpt_readDirAndSetWallpaper( obrwConfig_getWallpaperDir() ) /* == EXIT_FAILURE */ )
	{
		freeAllToClose();
		obrwLogger_error("Wallpaperoptions error!");
	}//if

	if( obrwConfig_writeSettingsToConfigFile() /* == EXIT_FAILURE */ )
	{
		freeAllToClose();
		obrwLogger_error("Wallpaper write error!");
	}//if

	//before exit free() local globs
	freeAllToClose();

	return EXIT_SUCCESS;
}//main( int, char** )

/** Free all used alocated heap-memory (if used) (to use before programm ends). */
void
freeAllToClose( void )
{
	obrwConfig_freeLocalsToClose();
	obrwWallpaperOpt_freeLocalsToClose();
}//freeAllToClose()
