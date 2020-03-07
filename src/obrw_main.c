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
	//TODO 
	//set global debug lvl
	OBRW_GLOBAL_DEBUG = 1;
	obrwUtils_setRandomCounterToZero();

    obrwLogger_success("Axo!");
    obrwLogger_info("Axo!");
    obrwLogger_warning("Axo!");
    obrwLogger_error("Axo!");
    obrwLogger_log("test", "test");

	if( 0 < OBRW_GLOBAL_DEBUG )
	{
		printf( "[MSG] OBRW DEBUG-LVL is %d.\n", OBRW_GLOBAL_DEBUG );
	}//if

	if( obrwChkExt_isFehOnSystem() == 0 )
	{
		freeAllToClose();
		printf( "[ERR] Feh is not installed!\n" );
		return EXIT_FAILURE;
	}//if

	if( obrwConfig_readConfigFile() /* == EXIT_FAILURE */)
	{
		freeAllToClose();
		printf( "[ERR] obrw.conf error!\n" );
		return EXIT_FAILURE;
	}//if

	if( obrwWallpaperOpt_readDirAndSetWallpaper( obrwConfig_getWallpaperDir() ) /* == EXIT_FAILURE */ )
	{
		freeAllToClose();
		printf( "[ERR] Wallpaperoptions error!\n" );
	}//if

	if( obrwConfig_writeSettingsToConfigFile() /* == EXIT_FAILURE */ )
	{
		freeAllToClose();
		printf( "[ERR] Wallpaper write error!\n" );
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
