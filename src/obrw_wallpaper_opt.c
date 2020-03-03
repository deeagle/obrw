/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_wallpaper_opt.c
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
 * \file obrw_wallpaper_opt.c
 *
 * \brief The file includes all methods and functions which are in context to all things about a wallpaper.
 *
 */

#include "obrw_wallpaper_opt.h"


static const size_t len_file_end = 4;
static const char *file_end_jpg = ".jpg";
static const char *file_end_png = ".png";
static const char *file_end_bmp = ".bmp";

static char** wallpaperNames;
static size_t wallpaperNamesLength = 0;
static int usedWallpaper = -1;


/** The getter-method to get the name of the last wallpaper. */
const char*
obrwWallpaperOpt_getUsedWallpaper( void )
{
	if( 0 > usedWallpaper )
	{
		//failure
		printf( "[DBG] no last wallpaper found.\n");

		return "";
	}//if

	if( 1 < OBRW_GLOBAL_DEBUG )
	{
		printf( "[DBG] %s\n", wallpaperNames[usedWallpaper] );
	}//if
	//success
	return &wallpaperNames[usedWallpaper][0];
}//obrwWallpaperOpt_getUsedWallpaper()


/** Checks a filename if it's a possible wallpaper. */
static int
obrwWallpaperOpt_filterWallpapersEndTag( const char* possibleWallpaperName )
{
	char buffer[len_file_end];
	size_t strLen = 0;

	if( possibleWallpaperName == NULL )
	{
		return -1;
	}//if

	buffer[0] = '\0';
	strLen = strlen( possibleWallpaperName );

	//fill buffer with cstrings endtag
	if( 5 < strLen )
	{
		buffer[0] = (char) tolower( (int) possibleWallpaperName[strLen - 4] );
		buffer[1] = (char) tolower( (int) possibleWallpaperName[strLen - 3] );
		buffer[2] = (char) tolower( (int) possibleWallpaperName[strLen - 2] );
		buffer[3] = (char) tolower( (int) possibleWallpaperName[strLen - 1] );
		buffer[4] = '\0';
	}//if
	else
	{
		return -1;
	}//else
	
	if( 1 < OBRW_GLOBAL_DEBUG )
	{
		printf( "[DBG] Buffer is %s\n", buffer );
	}//if

	//checks the endtag
	switch( buffer[1] )
	{
		//checks the start of endtag 'j' for 'jpg'
		case 'j':
				if( 0 == memcmp( buffer, file_end_jpg, len_file_end ) )
				{
					if( 1 < OBRW_GLOBAL_DEBUG )
					{
						printf( "[DBG] Possible Wallpaper (.jpg) found.\n" );
					}//if
				}//if
				else
				{
					return -2;
				}//else

				break;
		//checks the start of endtag 'p' for 'png'
		case 'p':
				if( 0 == memcmp( buffer, file_end_png, len_file_end ) )
				{
					if( 1 < OBRW_GLOBAL_DEBUG )
					{
						printf( "[DBG] Possible Wallpaper (.png) found.\n" );
					}//if
				}//if
				else
				{
					return -2;
				}//else
				
				break;
		//checks the start of endtag 'b' for 'bmp'
		case 'b':
				if( 0 == memcmp( buffer, file_end_bmp, len_file_end ) )
				{
					if( 1 < OBRW_GLOBAL_DEBUG )
					{
						printf( "[DBG] Possible Wallpaper (.bmp) found.\n" );
					}//if
				}//if
				else
				{
					return -2;
				}//else

				break;
		//the endtag is not in mind or implemented
		default:
				if( 1 < OBRW_GLOBAL_DEBUG )
				{
					printf( "[DBG] Endtag not in mind.\n" );
				}//if
	}//switch
	
	return 0;
}//obrwWallpaperOpt_filterWallpapersEndTag( const char* )


//TODO
/** Checks a filename if it's a possible wallpaper. */
static int
obrwWallpaperOpt_filterWallpapersMagicByte( const char* possibleWallpaperName )
{
	if( possibleWallpaperName == NULL )
	{
		return -1;
	}//if 

	return 0;
}//obrwWallpaperOpt_filterWallpapersMagicByte( const char* )


//TODO
/** Add a wallpaper to the wallpaper array. */
static int
obrwWallpaperOpt_addWallpaper( const char* wallpaper )
{
	if( NULL == wallpaper )
	{
		return -1;
	}//if 

	//only do something, if max-wallpaper-border isn't reached
	//init of wallpaperNamesLength is -1
	if( MAX_WALLPAPERS < wallpaperNamesLength )
	{
		if( 0 < OBRW_GLOBAL_DEBUG )
		{
			printf( "[DBG] Max count of wallpapers reach.\n" );
			return -2;
		}//if
	}//if

	//if wallpaperarray doesn't exist, get memory (4096) for
	if( !wallpaperNames )
	{
		wallpaperNames = (char**) calloc( WP_MEMORY_SIZE, sizeof( char* ) );

		//if wallpaperarray doesn't exist yet, get half memory (2048) for
		if( !wallpaperNames )
		{
			wallpaperNames = (char**) calloc( ( WP_MEMORY_SIZE / 2 ), sizeof( char* ) );
		}//if
		
		if( !wallpaperNames )
		{
			//error no memory avaiable
			printf( "[ERR] Could't allocate Memory!\n" );
			return -3;
		}//if

		//after allocate set length of array to 0
		wallpaperNamesLength = 0;
	}//if

	//TODO 
	//Enough memory avaiable to store next wallpaper?
	wallpaperNames[wallpaperNamesLength] = (char*) malloc( sizeof( char ) * strlen( wallpaper) + 1 );
	strncpy( wallpaperNames[wallpaperNamesLength], wallpaper, strlen( wallpaper ) + 1 );
	wallpaperNames[wallpaperNamesLength][strlen( wallpaper ) + 1] = '\0';

	if( 1 < OBRW_GLOBAL_DEBUG )
	{	
		printf( "[DBG] Add file %zu = %s\n", wallpaperNamesLength, wallpaper );
	}//if

	wallpaperNamesLength++;

	return 0;
}//obrwWallpaperOpt_addWallpaper( const char* )


/** Reads the wallpaperdir, add wallpaper and set it. */
int
obrwWallpaperOpt_readDirAndSetWallpaper( const char* dirPath )
{
	DIR* wpDir = NULL;
	struct dirent *entry = NULL;
	int wpCounter = 0;
	int wpEntry = -1;


	if( dirPath == NULL )
	{
		return EXIT_FAILURE;
	}//if
	else
	{
		if( 0 < OBRW_GLOBAL_DEBUG )
		{
			//FIXME
			printf( "[DBG] Wallpaperpath is %s.\n", dirPath );
		}//if
	}//else

	//Open DIR /.../wallpaper/
	if( ( wpDir = opendir( dirPath ) ) != NULL )
	{
		//counts entries in DIR
		entry = readdir( wpDir );
		while( entry )
		{
			wpCounter++;
			entry = readdir( wpDir );
		}//while

		if( 0 < wpCounter )
		{
			//sets dirPointer back to start setting
			rewinddir( wpDir );
			wpEntry = 0;

			//forward pointer in DIR
			entry = readdir( wpDir );
			while( entry )
			{
				if( strcmp( entry -> d_name, "." ) && strcmp( entry -> d_name, ".." ) )
				{
					//FILTER End-Tags
					if( 0 == obrwWallpaperOpt_filterWallpapersEndTag( entry -> d_name ) )
					{
						//TODO FILTER Magic-Bytes
						if( 0 == obrwWallpaperOpt_filterWallpapersMagicByte( entry -> d_name ) )
						{
							//FIXME
							//printf( "[DBG] File %d = %s\n", wpEntry, entry -> d_name );
							wpEntry++;
							if( 0 == obrwWallpaperOpt_addWallpaper( entry -> d_name ) )
							{
							}//if
							else
							{
								return EXIT_FAILURE;
							}//else
						}//if
					}//if
				}//if
				else
				{
					//dirname here is '.' and '..'
				}//else

				//forward pointer in DIR 
				entry = readdir( wpDir );
			}//while

			if( 0 < OBRW_GLOBAL_DEBUG )
			{
				printf( "[DBG] Count of found wallpapers is %d.\n", wpEntry );
			}//if
		}//if
		else
		{
			printf( "[ERR] No Wallpapers in wallpaperpath avaiable.\n" );
			return EXIT_FAILURE;
		}//else

		closedir( wpDir );

		obrwWallpaperOpt_chooseWallpaperAndTryToSet( dirPath );
	}//if
	else
	{
		printf( "[ERR] Wallpaperdir isn't avaiable!\n" );
		return EXIT_FAILURE;
	}//else

	return EXIT_SUCCESS;
}//obrwWallpaperOpt_readWallpaperDir( const char* )


//TODO
/** Choose some wallpaper and tries to set a random wallpaper. */
static int
obrwWallpaperOpt_chooseWallpaperAndTryToSet( const char* dirPath )
{
	if( NULL == wallpaperNames || NULL == dirPath )
	{
		if( NULL == wallpaperNames )
		{
			printf( "[ERR] Problem with stored wallpapers.\n" );
		}//if

		if( NULL == dirPath )
		{
			printf( "[ERR] No dirPath set.\n" );
		}//if
		
		//failure
		return -1;
	}//if

    int usedWallpaper;
    if( obrwConfig_getWallpaperLastSet() == NULL )
    {
        usedWallpaper = obrwUtils_randomDigit() % wallpaperNamesLength;
    }
    else
    {
        do
        {
            usedWallpaper = obrwUtils_randomDigit() % wallpaperNamesLength;
        }//do
        while( 0 == strcmp( obrwConfig_getWallpaperLastSet(), wallpaperNames[usedWallpaper] ) );//while
    }

	if( 0 != obrwWallpaperOpt_setWallpaperWithFeh( dirPath, wallpaperNames[usedWallpaper] ) )
	{
		usedWallpaper = -1;
		//failure
		return -2;
	}//if
		
	//success
	return 0;
}//obrwWallpaperOpt_chooseWallpaperAndTryToSet()


//TODO
/** Set a wallpaper with the external tool feh. */
int
obrwWallpaperOpt_setWallpaperWithFeh( const char* dirPath, const char* wpToSet )
{
	char* sysCmd;
	const char* fehCmd;
	size_t sysCmdLen = 0;

	if( NULL == wpToSet )
	{
		if( NULL == wpToSet )
		{
			printf( "[ERR] No wallpaper to set.\n" );
		}//if

		//failure
		return -1;
	}//if

	//feh command to set a wallpaper over full displaysize
	//'feh --bg-scale /wonderfull/canonical/file.name'
	// Chars   01234567890 1234     --> 14 chars
	//sysCmd = feh --bg-sc ale		--> 14 chars
	fehCmd = "feh --bg-scale \0";
	sysCmdLen = strlen( fehCmd ) + strlen( dirPath ) + strlen( wpToSet ) + 1;

	sysCmd = (char*) malloc( sizeof( char ) * sysCmdLen );

	if( NULL == sysCmd )
	{
		if( 0 < OBRW_GLOBAL_DEBUG )
		{
			printf( "[ERR] Get no heap-space for feh-string.\n" );
		}//if 

		//failure -2;
		return -2;
	}//if


	//TODO if one failure, free it!
	strncpy( sysCmd, fehCmd, strlen( fehCmd ) );
	strncat( sysCmd, dirPath, strlen( dirPath ) );
	strncat( sysCmd, wpToSet, strlen( wpToSet ) );

	if( 0 < OBRW_GLOBAL_DEBUG )
	{
		//FIXME
		printf( "[DBG] Try to set Wallpaper: %s\n", sysCmd );
	}//if
	
	//SHELL
	system( sysCmd );

	obrwUtils_freeCString( sysCmd );

	//success
	return 0;
}//obrwWallpaperOpt_setWallpaperWithFeh( const char* )


//TODO
//do it nice, not so dirty
/** Free all used allocated heap-memory (if used). */ 
void
obrwWallpaperOpt_freeLocalsToClose( void )
{
	size_t i = 0;

	if( wallpaperNames )
	{
		while( i < wallpaperNamesLength )
		{
			//TODO
			free( wallpaperNames[i] );
			wallpaperNames[i] = NULL;
			i++;
		}//while

		//TODO 
		//free char** wallpaperNames
		//---------------------------------
		//free( wallpaperNames );
		//wallpaperNames = NULL;

		wallpaperNamesLength = -1;
	}//if
}//obrwWallpaperOpt_freeLocalsToClose()
