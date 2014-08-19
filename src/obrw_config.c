/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_config.c
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
 * \file obrw_config.c
 *
 * \brief The file includes the definitons of functions which are associated with the configfile '~/.obrw.conf'.
 *
 */
#include "obrw_config.h"


static const char* obrwConf = "/.obrw.conf\0";
static char* userHome = NULL;
static char* wallpaperDir = NULL;
static char* wallpaperLast = NULL;


/** Returns the actually wallpaperpath (DIR which includes the wallpapers). */
const char* 
obrwConfig_getWallpaperDir( void )
{
	return wallpaperDir;
}//obrwConfig_getWallpaperDir()


/** The getter-method of the last set wallpaper, included in the configfile. */
const char*
obrwConfig_getWallpaperLastSet( void )
{
	return wallpaperLast;
}//obrwConfig_getWallpaperLastSet()


/** The setter-method to set the locale userhome. */
static void
obrwConfig_setUserHomeDir( void )
{
	userHome = obrwUtils_getUserHomeDir();
}//obrwConfig_setUserHomeDir()


/** Tests the configfile, if it's exists, is readable and writeable. */
static int
obrwConfig_isConfigFileReadWriteable( void )
{ 
	char* configPath;

	obrwConfig_setUserHomeDir();

	if( userHome == NULL )
	{
		printf( "[ERR] No user homedir avaiable\n" );
		return EXIT_FAILURE;
	}//if

	//if( userHome == "NOHOME" )
	if( strncmp( userHome, "NOHOME", 6 ) == 0 )
	{
		printf( "[ERR] User home = NOHOME !?\n" );
		return EXIT_FAILURE;
	}//if 
	
	if( 0 < OBRW_GLOBAL_DEBUG ) 
	{
		//FIXME
		printf( "[DBG] home is %s\n", userHome );
	}//if
	configPath = obrwString_2CStringsTo1( userHome, obrwConf );

	// $USERHOME/.obrw.config exists and accessable?
	if( access( configPath, EXIST ) != -1 )
	{
		if( access( configPath, READ ) != -1 )
		{
			if( access( configPath, WRITE ) != -1 )
			{
			}//if
			else
			{
				printf( "[ERR] %s exists, is readable but isn't writeable\n", configPath );
				return EXIT_FAILURE;
			}//else
		}//if
		else
		{
			//FIXME
			printf( "[ERR] %s exist but isn't readable\n", configPath );
			return EXIT_FAILURE;
		}//else
	}//if
	else
	{
		//FIXME
		printf( "[ERR] %s doesn't exist\n", configPath );
		return EXIT_FAILURE;
	}//else

	if( 1 < OBRW_GLOBAL_DEBUG )
	{
		//FIXME
		printf( "[DBG] Config Access (EXIST) is %d and Access (READ) is %d\n", access( configPath, EXIST ), access( configPath, READ ) );
	}//if
	
	if( 0 < OBRW_GLOBAL_DEBUG )
	{
		//FIXME
		printf( "[DBG] obrw.conf is: %s (EXIST and READABLE)\n", configPath );
	}//if

	obrwUtils_freeCString( configPath );

	return EXIT_SUCCESS;
}//obrwConfig_isConfigFileReadable()


/** Read the configfile and parse included wallpaperpath and last set wallpaper. */
int
obrwConfig_readConfigFile( void )
{
	FILE *fp;
	char* lineBuffer;
	char* filename; 
	char* wpDir;
	char* lastSet;
	char *bufP;
	int bufferSize = 256;

	if( obrwConfig_isConfigFileReadWriteable() == EXIT_FAILURE )
	{
		printf( "[ERR] Configfile problems detect.\n" );
		return EXIT_FAILURE;
	}//if
	
	if( userHome == NULL )
	{
		return EXIT_FAILURE;
	}//if
	
	filename = obrwString_2CStringsTo1( userHome, obrwConf );

	// (1) open file
	if( ( fp = fopen( filename, "r" ) ) != NULL ) 
	{
		lineBuffer = (char*) malloc( sizeof( char ) * bufferSize );
		lineBuffer[0] = '\0';

		// (2) work with file
		while( fgets( lineBuffer, bufferSize, fp ) != NULL )
		{
			bufP = strchr( lineBuffer, '\n' );
			
			//fgets succeeds -> scan for \n and set to \0
			if( bufP )
			{
				*bufP = '\0';
			}//if

			switch( lineBuffer[0] )
			{
				//checks if the line starts with '#'
				case '#':
						//next line
						if( 1 < OBRW_GLOBAL_DEBUG )
						{
							//FIXME
							printf( "[DBG] Commentline found --> %s\n", lineBuffer );
						}//if

						break;
				//checks if the line starts with 'w' --> wpDir
				case 'w':
						if( strncmp( lineBuffer, "wpDir =", 7 ) == 0 )
						{
							if( 0 < OBRW_GLOBAL_DEBUG )
							{
								//FIXME
								printf( "[DBG] wpDir is %s\n", lineBuffer );
							}//if

							if( ( wpDir = obrwString_parseConfigFileFor( lineBuffer ) ) == NULL )
							{
								printf( "[ERR] wallpaperDir is NULL.\n" );
								return EXIT_FAILURE;
							}//if
							else
							{
								wallpaperDir = (char*) malloc( sizeof( char ) * strlen( wpDir ) + 1 );

								if( wallpaperDir )
								{
									strncpy( wallpaperDir, wpDir, strlen( wpDir ) );
								}//if
							}//else
						}//if

						break;
				//checks if the line starts with 'l' --> lastSet
				case 'l':
						if( strncmp( lineBuffer, "lastSet =", 9 ) == 0 )
						{
							if( 0 < OBRW_GLOBAL_DEBUG )
							{
								//FIXME
								printf( "[DBG] lastSet is %s\n", lineBuffer );
							}//if
							
							if( ( lastSet = obrwString_parseConfigFileFor( lineBuffer ) ) == NULL )
							{
								printf( "[ERR] lastSet wallpaper is NULL.\n" );
								return EXIT_FAILURE;
							}//if
							else
							{
								wallpaperLast = (char*) malloc( sizeof( char ) * strlen( lastSet ) + 1 );

								if( wallpaperLast )
								{
									strncpy( wallpaperLast, lastSet, strlen( lastSet ) );
								}//if
							}//else
						}//if

						break;
				//checks if the line starts with ' '
				default :
						//next line
						if( 1 < OBRW_GLOBAL_DEBUG )
						{
							printf( "[DBG] Empty line in configfile found.\n" );
						}//if
				}//switch
		}//while

		// (3) close file
		fclose( fp );
	}//if
	else
	{
		printf( "[ERR] Configfile could't not opened (but checked?).\n" );
		return EXIT_FAILURE;
	}//else

	obrwUtils_freeCString( lineBuffer );
	obrwUtils_freeCString( filename );
	obrwUtils_freeCString( wpDir );
	obrwUtils_freeCString( lastSet );

	//success
	return EXIT_SUCCESS;
}//obrwConfig_readConfigFile()


/** Write the now used settings into the configfile. */
int
obrwConfig_writeSettingsToConfigFile( void )
{
	FILE *fp;
	char* lineBuffer;
	char* filename;
	char* configNow;
	const char* toSet;
	char* bufP;
	int bufferSize = 256;

	//is checked at startup
	//obrwConfig_isConfigFileReadWriteable()
	
	filename = obrwString_2CStringsTo1( userHome, obrwConf );

	// (1) open file
	if( ( fp = fopen( filename, "r+" ) ) != NULL )
	{
		lineBuffer = (char*) malloc( sizeof( char ) * bufferSize );
		lineBuffer[0] = '\0';
		configNow = (char*) malloc( sizeof( char ) * 4096 );
		configNow[0] = '\0';

		// (2) work file
		while( fgets( lineBuffer, bufferSize, fp ) != NULL )
		{
			bufP = strchr( lineBuffer, '\n' );

			//fgets succeeds -> scan for \n and set to \0
			if( bufP )
			{
				*bufP = '\0';
			}//if
			
			//if( strncmp( lineBuffer[0], 'w', 1 ) == 0 )
			if( lineBuffer[0] == 'l' )
			{
				if( strncmp( lineBuffer, "lastSet = ", 10 ) == 0 )
				{
					//FIXME
					strcat( configNow, "lastSet = \"" );
					toSet = obrwWallpaperOpt_getUsedWallpaper();
					strncat( configNow, toSet, strlen( toSet ) );
					strncat( configNow, "\"\n", 2 );
				}//if
				else
				{
					strncat( configNow, lineBuffer, strlen( lineBuffer ) );
					strncat( configNow, "\n", 1 );
				}//else
			}//if
			else
			{
				strncat( configNow, lineBuffer, strlen( lineBuffer ) );
				strncat( configNow, "\n", 1 );
			}//else
		}//while

		// (3) close file
		fclose( fp );

		if( 1 < OBRW_GLOBAL_DEBUG )
		{
			//FIXME
			printf( "[DBG] >>>\n[DBG] New configfile to write:\n" );
			printf( "----------------------------------------------------\n" );
			printf( "%s", configNow );
			printf( "----------------------------------------------------\n" );
			printf( "[DBG] <<<\n" );
		}//if
	}//if
	else
	{
		printf( "[ERR] Couldn't open configfile to read old config.\n" );
		return EXIT_FAILURE;
	}//else

	// (1) open file
	if( ( fp = fopen( filename, "w" ) ) != NULL )
	{
		// (2) work file
		fputs( configNow, fp );

		// (3) close file
		fclose( fp );	
	}//if
	else
	{
		printf( "[ERR] Couldn't open configfile to write new config.\n" );
	}//else
	
	//success
	return EXIT_SUCCESS;
}//obrwConfig_writeSettingsToConfigFile()


/** Free memory of used locale variables. */
void 
obrwConfig_freeLocalsToClose( void )
{
	if( wallpaperDir )
	{		
		obrwUtils_freeCString( wallpaperDir );
	}//if

	if( wallpaperLast )
	{
		obrwUtils_freeCString( wallpaperLast );
	}//if
}//obrwConfig_freeLocalsToClose()
