/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_config.h
 *
 * \brief The file includes the definitions of functions which are associated
 * with the configfile `~/.obrw.conf`.
 */
#ifndef OBRW_CONFIG_H
#define OBRW_CONFIG_H

#include <string.h>
#include <sys/stat.h>  /* LINUX / UNIX */
#include <sys/types.h> /* LINUX / UNIX */

#ifdef __unix__

#include <unistd.h>

#define EXIST F_OK
#define EXEC X_OK
#define WRITE W_OK
#define READ R_OK
#endif

#include <stdio.h>

#include "obrw_logger.h"
#include "obrw_string.c"
#include "obrw_utils.c"
#include "obrw_wallpaper_opt.h"

static const char *obrwConf; /** Config-filename (/.obrw.conf)*/
static char *userHome;       /** Holder of user home-path */
static char *wallpaperDir;   /** Canonical path of wallpaper DIR */
static char *wallpaperLast;  /** Last set wallpaper */

/**
 * The setter-method to set the locale user home.
 * Set the local userHome with help of the getUserHomeDir-method in obrw_utils.c
 *
 * \return Nothing, it's void.
 */
void obrwConfig_setUserHomeDir(void);

/**
 * Tests the configfile, if it's exists, is readable and writeable.
 *
 * \return If the file is read and writeable the method finishes with
 * EXIT_SUCCESS, if any error occur EXIT_FAILURE returns. \retval EXIT_SUCCESS
 * success. \retval EXIT_FAILURE failed.
 */
int obrwConfig_isConfigFileReadWriteable(void);

/**
 * The getter-method of the wallpaper dir, included in the configfile.
 *
 * \return The actually wallpaper path (DIR which includes the wallpapers) as
 * const char*. \retval Wallpaper path Canonical path of the set wallpaper path
 * (Exp. /foo/bar/ ). \retval NULL Entry doesn't exist.
 */
const char *obrwConfig_getWallpaperDir(void);

/**
 * Sets the wallpaper directory.
 * <p>
 * Adds a trailing slash if not exists.
 *
 * @param wpDir The wallpaper directory path to set.
 * @return The wallpaper directory with trailing slash, otherwise
 * <code>NULL</code>.
 */
const char *obrwConfig_setWallpaperDir(const char *);

/**
 * The getter-method of the last set wallpaper, included in the configfile.
 *
 * \return The last set wallpaper (lastWP-entry in configfile) as const char*.
 * \retval Last-Wallpaper  Name of the last set wallpaper (Exp. file.jpg ).
 * \retval "FIRST-SESSION" First session that OBRW runs.
 * \retval NULL Entry doesn't exist.
 */
const char *obrwConfig_getWallpaperLastSet(void);

/**
 * Read the configfile and parse included wallpaper path and last set wallpaper
 *
 * \return If the file (~/.obrw.conf) is read and writeable, includes correct
 * entries for wpDir and lastWP, the method finishes with EXIT_SUCCESS, if any
 * error occur EXIT_FAILURE returns. \retval EXIT_SUCCESS success. \retval
 * EXIT_FAILURE failed.
 */
int obrwConfig_readConfigFile(void);

/**
 * Write the now used settings into the configfile.
 *
 * \return If the file (~/.obrw.conf) is read and writeable (checked at
 * ,obrwConfig_getWallpaperDir()) the method finishes with EXIT_SUCCESS, if any
 * error occur EXIT_FAILURE returns. \retval EXIT_SUCCESS success. \retval
 * EXIT_FAILURE failed.
 */
int obrwConfig_writeSettingsToConfigFile(struct wallpaper *);

/**
 * Free memory of used locale variables with help of the free-methods in
 * obrw_utils.c
 *
 * \return Nothing, it's void.
 */
void obrwConfig_freeLocalsToClose(void);

#endif  // OBRW_CONFIG_H
