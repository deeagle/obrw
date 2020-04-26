/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_config.h
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
 * \file obrw_config.h
 *
 * \brief The file includes the definitons of functions which are associated with the configfile '~/.obrw.conf'.
 *
 */
#ifndef OBRW_CONFIG_H
#define OBRW_CONFIG_H

#include <string.h>
#include <sys/stat.h>	/* LINUX / UNIX */
#include <sys/types.h>  /* LINUX / UNIX */
#ifdef __unix__
	#include <unistd.h>
	#define EXIST	F_OK
	#define EXEC	X_OK
	#define WRITE	W_OK
	#define READ	R_OK
#endif
#include <stdio.h>
#include "obrw_logger.h"
#include "obrw_string.c"
#include "obrw_utils.c"
#include "obrw_wallpaper_opt.h"


static const char* obrwConf;	/** Configfilename (/.obrw.conf)*/
static char* userHome;			/** Holder of userhomepath */
static char* wallpaperDir;		/** Canonical path of wallpaper DIR */
static char* wallpaperLast;		/** Last seted wallpaper */

/** 
 * The setter-method to set the locale userhome.
 * Set the local userHome with help of the getUserHomeDir-method in obrw_utils.c
 *
 * \return Nothing, it's void.
 */
void obrwConfig_setUserHomeDir( void );

/** 
 * Tests the configfile, if it's exists, is readable and writeable. 
 *
 * \return If the file is read and writeable the method finishes with EXIT_SUCCESS, if any error occures EXIT_FAILURE returns.
 * \retval EXIT_SUCCESS success.
 * \retval EXIT_FAILURE failed.
 */
int obrwConfig_isConfigFileReadWriteable( void );

/**
 * The getter-method of the wallpaperdir, included in the configfile.
 *
 * \return The actually wallpaperpath (DIR which includes the wallpapers) as const char*.
 * \retval Wallpaperpath Canonical path of the seted wallpaperpath (Exp. /foo/bar/ ).
 * \retval NULL Entry doesn't exist.
 */
const char* obrwConfig_getWallpaperDir( void );

/** 
 * The getter-method of the last set wallpaper, included in the configfile.
 *
 * \return The last set wallpaper (lastWP-entry in configfile) as const char*.
 * \retval Last-Wallpaper  Name of the last seted wallpaper (Exp. file.jpg ).
 * \retval "FIRST-SESSION" First session that OBRW runs.
 * \retval NULL Entry doesn't exist.
 */
const char* obrwConfig_getWallpaperLastSet( void );

/** 
 * Read the configfile and parse included wallpaperpath and last set wallpaper
 *
 * \return If the file (~/.obrw.conf) is read and writeable, includes correct entries for wpDir and lastWP, the method finishes with EXIT_SUCCESS, if any error occures EXIT_FAILURE returns.
 * \retval EXIT_SUCCESS success.
 * \retval EXIT_FAILURE failed.
 */
int obrwConfig_readConfigFile( void );

/**
 * Write the now used settings into the configfile.
 *
 * \return If the file (~/.obrw.conf) is read and writeable (checked at ,obrwConfig_getWallpaperDir()) the method finishes with EXIT_SUCCESS, if any error occures EXIT_FAILURE returns.
 * \retval EXIT_SUCCESS success.
 * \retval EXIT_FAILURE failed.
 */
int obrwConfig_writeSettingsToConfigFile( struct wallpaper* );

/** 
 * Free memory of used locale variables with help of the free-methods in obrw_utils.c
 *
 * \return Nothing, it's void.
 */
void obrwConfig_freeLocalsToClose( void );


#endif //OBRW_CONFIG_H
