/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_wallpaper_opt.h
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
 * \file obrw_wallpaper_opt.h
 *
 * \brief The file includes all methods and functions which are in context to all things about a wallpaper.
 *
 */

#ifndef OBRW_WALLPAPER_OPT_H
#define OBRW_WALLPAPER_OPT_H

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>	/* LINUX / UNIX */
#include <sys/types.h>	/* LINUX / UNIX */
#ifdef __UNIX__
	#include <unistd.h>
	#define FILE_EXIST	F_OK
	#define FILE_EXEC	X_OK
	#define FILE_WRITE	W_OK
	#define FILE_READ	R_OK
#endif
#include "obrw_config.h"
#include "obrw_globals.h"


/** Max counts of stored wallpapers. */
#define MAX_WALLPAPERS	  50
/** Max memory size of array for wallpapers */
#define WP_MEMORY_SIZE	4096
/** file isn't DIR */
#define DIR_F			   1
/** file is DIR */
#define DIR_D			   2
/** file is DIR but didn't readable */
#define DIR_DNR			   3

static const size_t len_file_end;
static const char* file_end_jpg;
static const char* file_end_png;
static const char* file_end_bmp;
static char** wallpaperNames;
static size_t wallpaperNamesLength;
static int usedWallpaper;


/**
 * Checks a filename if it's a possible wallpaper (easy test above endtag). For example:\n
 * foo_bar.jpg -> .jpg == picture-tag 
 *
 * \returns If it's a possible wallpaper it will return 0, or a negative digit if an error oncures.
 * \retval 0 possible wallpaper.
 * \retval -1 wallpaperpath is NULL.
 * \retval -2 endtag not known or no wallpaper.
 */
static int obrwWallpaperOpt_filterWallpapersEndTag( const char* );

/** 
 * Checks a filename if it's a possible wallpaper (2nd test above magicbytes of file)
 * 
 * \returns TODO
 */
static int obrwWallpaperOpt_filterWallpapersMagicByte( const char* );

/**
 * Add's a wallpaper to the wallpaper-array. If it's the first wallpaper to add, the methods will try to get 1st 4096 bytes of heap-memory. If it fails it will try to get 2048. If it fails an error will occure.
 * If the array has the maximum of wallpapers reach, the wallpaper will not add.
 *
 * \returns The method will be return 0 if the wallpaper is added in the array.
 * \retval 0 wallpaper added.
 * \retval -1 wallpaper is NULL.
 * \retval -2 max count reached, wallpaper thrown away.
 * \retval -3 could not alocate heap-space .
 */
static int obrwWallpaperOpt_addWallpaper( const char* );

/**
 * Choose some wallpaper and tries to set a random wallpaper.
 *
 * \returns If the wallpaper is set it will be return 0.
 * \retval 0 success, wallpaper could be set.
 * \retval -1 fail, no dirpath seteda.
 * \retval -2 fail, error with feh.
 */
static int obrwWallpaperOpt_chooseWallpaperAndTryToSet( const char* );

/**
 * The getter-method to get the name of the last used wallpaper.
 *
 * \returns The name of the last used wallpaper or NULL if failure.
 * \retval wallpapername success.
 * \retval NULL fail.
 */
const char* obrwWallpaperOpt_getUsedWallpaper( void );

/**
 * Reads the wallpaperdir (attribute), add the wallpapers to a list and tries to set a random of the wallpapers.
 *
 * \returns If some wallpaper is set, it will return EXIT_SUCCESS.
 * \retval EXIT_SUCCESS success.
 * \retval EXIT_FAILED fail.
 */
int obrwWallpaperOpt_readDirAndSetWallpaper( const char* );

/**
 * Set a wallpaper with the external tool feh 
 *
 * \returns If the wallpaper could be set with feh, it will return 0.
 * \retval 0 success, wallpaper set.
 * \retval -1 wallpaper is NULL.
 * \retval -2 couldn't alocate heap-space.
 */
int obrwWallpaperOpt_setWallpaperWithFeh( const char*, const char* );

/**
 * Free all used allocated heap-memory (if used, to use before programm ends -> success and fail).
 *
 * \returns Nothing, it's void
 */
void obrwWallpaperOpt_freeLocalsToClose( void );


#endif //OBRW_WALLPAPER_OPT_H
