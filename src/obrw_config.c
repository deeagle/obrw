/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_config.c
 *
 * \brief The file includes the definitions of functions which are associated
 * with the configfile '~/.obrw.conf'.
 */
#include "obrw_config.h"

static const char *obrwConf = "/.obrw.conf\0";
static char *userHome = NULL;
static char *wallpaperDir = NULL;
static char *wallpaperLast = NULL;

/** Returns the actually wallpaper path (DIR which includes the wallpapers). */
const char *obrwConfig_getWallpaperDir(void) {
    return wallpaperDir;
}

const char *obrwConfig_setWallpaperDir(const char *wpDir) {
    if (NULL == wpDir || strlen(wpDir) < 1) {
        obrwLogger_warning("Given wallpaper directory path was empty.");
        return NULL;
    }

    int wpDirHasTrailingSlash = FALSE;
    // has given wpDir a trailing /
    if (wpDir[strlen(wpDir) - 1] == '/') {
        obrwLogger_debug("Wallpaper path is with trailing slash, that's good.");
        wpDirHasTrailingSlash = TRUE;
        wallpaperDir = (char *) malloc(sizeof(char) * (strlen(wpDir) + 1));
    } else {
        obrwLogger_debug("Wallpaper path is without trailing slash.");
        wpDirHasTrailingSlash = FALSE;
        wallpaperDir = (char *) malloc(sizeof(char) * (strlen(wpDir) + 2));
    }

    if (wallpaperDir) {
        strncpy(wallpaperDir, wpDir, strlen(wpDir));
        if (wpDirHasTrailingSlash == FALSE) {
            obrwLogger_debug("We add a trailing slash to the wallpaper path.");
            wallpaperDir[strlen(wpDir)] = '/';
            wallpaperDir[strlen(wpDir) + 1] = '\0';
        }
    }

    return obrwConfig_getWallpaperDir();
}

/** The getter-method of the last set wallpaper, included in the configfile. */
const char *obrwConfig_getWallpaperLastSet(void) {
    return wallpaperLast;
}

/** The setter-method to set the locale user home. */
void obrwConfig_setUserHomeDir(void) {
    userHome = obrwUtils_getUserHomeDir();
}

/** Tests the configfile, if it's exists, is readable and writeable. */
int obrwConfig_isConfigFileReadWriteable(void) {
    char *configPath;

    obrwConfig_setUserHomeDir();

    if (userHome == NULL) {
        obrwLogger_error("No user homedir available");
        return EXIT_FAILURE;
    }

    // if( userHome == "NOHOME" )
    if (strncmp(userHome, "NOHOME", 6) == 0) {
        obrwLogger_error("No user home available: User home = NOHOME !?");
        return EXIT_FAILURE;
    }

    char *logMsg = (char *) malloc((16 + strlen(userHome)) * sizeof(char));
    sprintf(logMsg, "User home is <%s>.", userHome);
    obrwLogger_debug(logMsg);
    obrwUtils_freeCString(&logMsg);

    configPath = obrwString_2CStringsTo1(userHome, obrwConf);

    // $USERHOME/.obrw.config exists and accessible?
    if (access(configPath, EXIST) != -1) {
        if (access(configPath, READ) != -1) {
            if (access(configPath, WRITE) != -1) {
            } else {
                char *message =
                        (char *) malloc((56 + strlen(configPath)) * sizeof(char));
                sprintf(message,
                        "Configfile <%s> exists and is readable, but not "
                        "writeable.",
                        configPath);
                obrwLogger_error(message);
                obrwUtils_freeCString(&message);

                return EXIT_FAILURE;
            }
        } else {
            char *message =
                    (char *) malloc((41 + strlen(configPath)) * sizeof(char));
            sprintf(message, "Configfile <%s> exists but is not readable.",
                    configPath);
            obrwLogger_error(message);
            obrwUtils_freeCString(&message);

            return EXIT_FAILURE;
        }
    } else {
        char *message =
                (char *) malloc((41 + strlen(configPath)) * sizeof(char));
        sprintf(message, "Configfile <%s> doesn't exists.", configPath);
        obrwLogger_error(message);
        obrwUtils_freeCString(&message);

        return EXIT_FAILURE;
    }

    char *logMsgConfigAccess = (char *) malloc(59 * sizeof(char));
    sprintf(logMsgConfigAccess,
            "Configfile access (EXIST) is <%d> and Access (READ) is <%d>.",
            access(configPath, EXIST), access(configPath, READ));
    obrwLogger_debug(logMsgConfigAccess);
    obrwUtils_freeCString(&logMsgConfigAccess);

    char *logMsgConfigReadable =
            (char *) malloc((38 + strlen(configPath)) * sizeof(char));
    sprintf(logMsgConfigReadable, "Configfile is <%s> (EXISTS and READABLE)",
            configPath);
    obrwLogger_debug(logMsgConfigReadable);
    obrwUtils_freeCString(&logMsgConfigReadable);

    obrwUtils_freeCString(&configPath);

    return EXIT_SUCCESS;
}

/** Read the configfile and parse included wallpaper path and last set wallpaper.
 */
int obrwConfig_readConfigFile(void) {
    FILE *fp;
    char *lineBuffer;
    char *filename;
    char *wpDir;
    char *lastSet;
    int bufferSize = 256;

    if (obrwConfig_isConfigFileReadWriteable() == EXIT_FAILURE) {
        obrwLogger_error("Configfile problems detect.");
        return EXIT_FAILURE;
    }

    obrwLogger_debug("Configfile is read and writeable.");

    if (userHome == NULL) {
        return EXIT_FAILURE;
    }

    obrwLogger_debug("User home is not NULL");

    filename = obrwString_2CStringsTo1(userHome, obrwConf);

    // (1) open file
    if ((fp = fopen(filename, "r")) != NULL) {
        lineBuffer = (char *) malloc(sizeof(char) * bufferSize);
        lineBuffer[0] = '\0';

        // (2) work with file
        while (fgets(lineBuffer, bufferSize, fp) != NULL) {
            char *bufP = strchr(lineBuffer, '\n');

            // fgets succeeds -> scan for \n and set to \0
            if (bufP) {
                *bufP = '\0';
            }

            char *logMsgFoundComment;

            switch (lineBuffer[0]) {
                // checks if the line starts with '#'
                case '#':
                    // next line
                    logMsgFoundComment = (char *) malloc(
                            (32 + strlen(lineBuffer)) * sizeof(char));
                    sprintf(logMsgFoundComment,
                            "Found comment in config file: <%s>", lineBuffer);
                    obrwLogger_debug(logMsgFoundComment);
                    obrwUtils_freeCString(&logMsgFoundComment);

                    break;
                    // checks if the line starts with 'w' --> wpDir

                case 'w':
                    if (strncmp(lineBuffer, "wpDir =", 7) == 0) {
                        char *logMsgFoundWallpaperKey = (char *) malloc(
                                (36 + strlen(lineBuffer)) * sizeof(char));
                        sprintf(logMsgFoundWallpaperKey,
                                "Found key 'wpDir =' in config file: <%s>",
                                lineBuffer);
                        obrwLogger_debug(logMsgFoundWallpaperKey);
                        obrwUtils_freeCString(&logMsgFoundWallpaperKey);

                        if ((wpDir = obrwString_parseConfigFileFor(
                                lineBuffer)) == NULL) {
                            obrwLogger_error("WallpaperDir is NULL.");
                            return EXIT_FAILURE;
                        } else {
                            obrwConfig_setWallpaperDir(wpDir);
                        }
                    }

                    break;
                    // checks if the line starts with 'l' --> lastSet

                case 'l':
                    if (strncmp(lineBuffer, "lastSet =", 9) == 0) {
                        char *logMsgFoundLastWallpaperKey = (char *) malloc(
                                (40 + strlen(lineBuffer)) * sizeof(char));
                        sprintf(logMsgFoundLastWallpaperKey,
                                "Found key 'lastSet =' in config file: <%s>",
                                lineBuffer);
                        obrwLogger_debug(logMsgFoundLastWallpaperKey);
                        obrwUtils_freeCString(&logMsgFoundLastWallpaperKey);

                        if ((lastSet = obrwString_parseConfigFileFor(
                                lineBuffer)) == NULL) {
                            obrwLogger_error("Last set wallpaper is NULL.");
                            return EXIT_FAILURE;
                        } else {
                            wallpaperLast = (char *) malloc(
                                    sizeof(char) * strlen(lastSet) + 1);

                            if (wallpaperLast) {
                                strncpy(wallpaperLast, lastSet,
                                        strlen(lastSet));
                            }
                        }
                    }

                    break;
                    // checks if the line starts with ' '
                default:
                    // next line
                    obrwLogger_debug("Empty line in configfile found.");
            }
        }

        // (3) close file
        fclose(fp);
    } else {
        obrwLogger_error("Configfile couldn't not opened (but checked?).");
        return EXIT_FAILURE;
    }

    obrwUtils_freeCString(&lineBuffer);
    obrwUtils_freeCString(&filename);
    obrwUtils_freeCString(&wpDir);
    obrwUtils_freeCString(&lastSet);

    return EXIT_SUCCESS;
}

/** Write the now used settings into the configfile. */
int obrwConfig_writeSettingsToConfigFile(const struct wallpaper *wallpaperItem) {
    FILE *fp;
    const char *filename;
    char *configNow;
    int bufferSize = 256;

    // is checked at startup
    // obrwConfig_isConfigFileReadWriteable()

    filename = obrwString_2CStringsTo1(userHome, obrwConf);

    char *msg = (char *) malloc(17 + strlen(filename));
    sprintf(msg, "Config file is <%s>.", filename);
    obrwLogger_debug(msg);
    obrwUtils_freeCString(&msg);

    if ((fp = fopen(filename, "r+")) != NULL) {
        char *lineBuffer = (char *) malloc(sizeof(char) * bufferSize);
        lineBuffer[0] = '\0';
        configNow = (char *) malloc(sizeof(char) * 4096);
        configNow[0] = '\0';

        while (fgets(lineBuffer, bufferSize, fp) != NULL) {
            char *bufP = strchr(lineBuffer, '\n');

            // fgets succeeds -> scan for \n and set to \0
            if (bufP) {
                *bufP = '\0';
            }

            // if( strncmp( lineBuffer[0], 'w', 1 ) == 0 )
            if (lineBuffer[0] == 'l') {
                obrwLogger_debug("Found line which starts with char 'l'");

                if (strncmp(lineBuffer, "lastSet = ", 10) == 0) {
                    obrwLogger_debug("Found line with 'lastSet' information");
                    strcat(configNow, "lastSet = \"");
                    const char *toSet = wallpaperItem->name;
                    strncat(configNow, toSet, strlen(toSet));
                    strcat(configNow, "\"\n");
                } else {
                    char *logMsg = (char *) malloc((28 + strlen(lineBuffer)) *
                                                   sizeof(char));
                    sprintf(logMsg, "Was no config value key: <%s>.",
                            lineBuffer);
                    obrwLogger_debug(logMsg);
                    obrwUtils_freeCString(&logMsg);

                    strncat(configNow, lineBuffer, strlen(lineBuffer));
                    strcat(configNow, "\n");
                }
            } else {
                strncat(configNow, lineBuffer, strlen(lineBuffer));
                strcat(configNow, "\n");
            }
        }

        // (3) close file
        fclose(fp);

        obrwLogger_debug("New configfile to write:");
        obrwLogger_debug(
                "----------------------------------------------------");
        obrwLogger_logMultiLine(DEBUG_TAG, configNow);
        obrwLogger_debug(
                "----------------------------------------------------");
    } else {
        obrwLogger_error("Couldn't open configfile to read old config.");
        return EXIT_FAILURE;
    }

    // (1) open file
    if ((fp = fopen(filename, "w")) != NULL) {
        // (2) work file
        fputs(configNow, fp);

        // (3) close file
        fclose(fp);
    } else {
        obrwLogger_error("Couldn't open configfile to write new config.");
    }

    // success
    return EXIT_SUCCESS;
}

/** Free memory of used locale variables. */
void obrwConfig_freeLocalsToClose(void) {
    if (wallpaperDir) {
        obrwUtils_freeCString(&wallpaperDir);
    }

    if (wallpaperLast) {
        obrwUtils_freeCString(&wallpaperLast);
    }
}
