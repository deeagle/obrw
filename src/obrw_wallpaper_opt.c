/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_wallpaper_opt.c
 *
 * \brief The file includes all methods and functions which are in context to
 * all things about a wallpaper.
 */
#include "obrw_wallpaper_opt.h"

static const size_t len_file_end = 4;
static const char *file_end_jpg = ".jpg";
static const char *file_end_png = ".png";
static const char *file_end_bmp = ".bmp";

static char **wallpaperNames;
static size_t wallpaperNamesLength = 0;

/** Checks a filename if it's a possible wallpaper. */
int obrwWallpaperOpt_filterWallpapersEndTag(const char *possibleWallpaperName) {
    // size of file ending + 1 for termination, e.g. .png\0
    char buffer[len_file_end + 1];
    size_t strLen = 0;

    if (possibleWallpaperName == NULL) {
        return -1;
    }

    buffer[0] = '\0';
    strLen = strlen(possibleWallpaperName);

    // fill buffer with cstrings endtag
    if (5 < strLen) {
        buffer[0] = (char) tolower((int) possibleWallpaperName[strLen - 4]);
        buffer[1] = (char) tolower((int) possibleWallpaperName[strLen - 3]);
        buffer[2] = (char) tolower((int) possibleWallpaperName[strLen - 2]);
        buffer[3] = (char) tolower((int) possibleWallpaperName[strLen - 1]);
        buffer[4] = '\0';
    } else {
        return -1;
    }

    char *logMsg = (char *) malloc((13 + strlen(buffer)) * sizeof(char));
    sprintf(logMsg, "Buffer is <%s>.", buffer);
    obrwLogger_debug(logMsg);
    obrwUtils_freeCString(&logMsg);

    // checks the endtag
    switch (buffer[1]) {
        // checks the start of endtag 'j' for 'jpg'
        case 'j':
            if (0 == memcmp(buffer, file_end_jpg, len_file_end)) {
                obrwLogger_debug("Possible Wallpaper (.jpg) found.");
            } else {
                return -2;
            }

            break;
            // checks the start of endtag 'p' for 'png'

        case 'p':
            if (0 == memcmp(buffer, file_end_png, len_file_end)) {
                obrwLogger_debug("Possible Wallpaper (.png) found.");
            } else {
                return -2;
            }

            break;
            // checks the start of endtag 'b' for 'bmp'

        case 'b':
            if (0 == memcmp(buffer, file_end_bmp, len_file_end)) {
                obrwLogger_debug("Possible Wallpaper (.bmp) found.");
            } else {
                return -2;
            }

            break;
            // the endtag is not in mind or implemented
        default:
            obrwLogger_debug("Endtag not in mind or implemented.");
    }

    return 0;
}

// TODO
/** Checks a filename if it's a possible wallpaper. */
int obrwWallpaperOpt_filterWallpapersMagicByte(
        const char *possibleWallpaperName) {
    if (possibleWallpaperName == NULL) {
        return -1;
    }

    return 0;
}

// TODO
/** Add a wallpaper to the wallpaper array. */
int obrwWallpaperOpt_addWallpaper(const char *wallpaper) {
    if (NULL == wallpaper) {
        return -1;
    }

    char *logMsg = (char *) malloc(27 * sizeof(char) * strlen(wallpaper));
    sprintf(logMsg, "Add possible wallpaper: <%s>.", wallpaper);
    obrwLogger_debug(logMsg);
    obrwUtils_freeCString(&logMsg);

    // only do something, if max-wallpaper-border isn't reached
    // init of wallpaperNamesLength is -1
    if (MAX_WALLPAPERS < wallpaperNamesLength) {
        obrwLogger_info("Max count of wallpapers reach.");
        return -2;
    }

    // if wallpaper array doesn't exist, get memory (4096) for
    if (!wallpaperNames) {
        wallpaperNames = (char **) calloc(WP_MEMORY_SIZE, sizeof(char *));

        // if wallpaper array doesn't exist yet, get half memory (2048) for
        if (!wallpaperNames) {
            wallpaperNames =
                    (char **) calloc((WP_MEMORY_SIZE / 2), sizeof(char *));
        }

        if (!wallpaperNames) {
            // error no memory available
            obrwLogger_error("Couldn't allocate Memory!");
            return -3;
        }

        // after allocate set length of array to 0
        wallpaperNamesLength = 0;
    }

    // TODO
    // Enough memory available to store next wallpaper?
    wallpaperNames[wallpaperNamesLength] =
            (char *) malloc(sizeof(char) * strlen(wallpaper) + 1);
    strncpy(wallpaperNames[wallpaperNamesLength], wallpaper,
            strlen(wallpaper) + 1);
    wallpaperNames[wallpaperNamesLength][strlen(wallpaper) + 1] = '\0';

    logMsg = (char *) malloc((12 + strlen(wallpaper)) * sizeof(char));
    sprintf(logMsg, "Add file <%s>.", wallpaper);
    obrwLogger_debug(logMsg);
    obrwUtils_freeCString(&logMsg);

    wallpaperNamesLength++;

    return 0;
}

/** Reads the wallpaper dir, add wallpaper and set it. */
int obrwWallpaperOpt_readDirAndSetWallpaper(const char *dirPath,
                                            struct wallpaper *wallpaperItem) {
    DIR *wpDir = NULL;
    const struct dirent *entry = NULL;
    int wpCounter = 0;

    if (NULL == dirPath || strlen(dirPath) < 1) {
        obrwLogger_error("No dirPath set.");

        return EXIT_FAILURE;
    }

    char *logMsg = (char *) malloc((22 + strlen(dirPath)) * sizeof(char));
    sprintf(logMsg, "Wallpaper path is <%s>.", dirPath);
    obrwLogger_debug(logMsg);
    obrwUtils_freeCString(&logMsg);

    // Open DIR /.../wallpaper/
    wpDir = opendir(dirPath);
    if (wpDir == NULL) {
        obrwLogger_error("Can't open given path of wallpaper directory.");

        return EXIT_FAILURE;
    }

    // counts entries in DIR
    entry = readdir(wpDir);
    while (entry) {
        wpCounter++;
        entry = readdir(wpDir);
    }

    if (0 < wpCounter) {
        int wpEntry = 0;
        // sets dirPointer back to start setting
        rewinddir(wpDir);

        // forward pointer in DIR
        entry = readdir(wpDir);
        while (entry) {
            if (0 != strcmp(entry->d_name, ".") ||
                0 != strcmp(entry->d_name, "..")) {
                // FILTER End-Tags
                if (0 ==
                    obrwWallpaperOpt_filterWallpapersEndTag(entry->d_name)) {
                    // TODO FILTER Magic-Bytes
                    if (0 == obrwWallpaperOpt_filterWallpapersMagicByte(
                            entry->d_name)) {
                        // printf( "[DBG] File %d = %s\n", wpEntry, entry ->
                        // d_name );
                        wpEntry++;
                        if (0 == obrwWallpaperOpt_addWallpaper(entry->d_name)) {
                        } else {
                            return EXIT_FAILURE;
                        }
                    }
                }
            } else {
                // dirname here is '.' and '..'
            }

            // forward pointer in DIR
            entry = readdir(wpDir);
        }

        // char length for wallpaper count: 1.000.000.000 = 10
        char *message = (char *) malloc((32 + 10) * sizeof(char));
        sprintf(message, "Count of found wallpapers is <%d>.", wpEntry);
        obrwLogger_info(message);
        obrwUtils_freeCString(&message);
    }

    closedir(wpDir);

    return obrwWallpaperOpt_chooseWallpaperAndTryToSet(dirPath, wallpaperItem);
}

/** Choose some wallpaper and tries to set a random wallpaper. */
int obrwWallpaperOpt_chooseWallpaperAndTryToSet(
        const char *dirPath, struct wallpaper *wallpaperItem) {
    obrwLogger_debug("Choose wallpaper and try to set.");

    if (NULL == wallpaperNames || NULL == dirPath || strlen(dirPath) < 1) {
        if (NULL == wallpaperNames) {
            obrwLogger_error("Problem with stored wallpapers.");
        }

        if (NULL == dirPath || strlen(dirPath) < 1) {
            obrwLogger_error("No dirPath set.");
        }

        return -1;
    }

    int usedWallpaperIndex;
    if (obrwConfig_getWallpaperLastSet() == NULL || wallpaperNamesLength == 1) {
        if (obrwConfig_getWallpaperLastSet() == NULL) {
            obrwLogger_debug("No last wallpaper found.");
        }

        if (wallpaperNamesLength == 1) {
            obrwLogger_debug(
                    "Last wallpaper will be ignored because it was only one "
                    "wallpaper found to choose.");
        }

        usedWallpaperIndex = obrwUtils_randomDigit() % wallpaperNamesLength;
    } else {
        do {
            usedWallpaperIndex = obrwUtils_randomDigit() % wallpaperNamesLength;
        } while (0 == strcmp(obrwConfig_getWallpaperLastSet(),
                             wallpaperNames[usedWallpaperIndex]));  // while
    }

    wallpaperItem->arrayIndex = usedWallpaperIndex;
    strcpy(wallpaperItem->name, wallpaperNames[usedWallpaperIndex]);

    return obrwWallpaperOpt_setWallpaperWithFeh(dirPath, wallpaperNames[usedWallpaperIndex]);
}

// TODO
/** Set a wallpaper with the external tool feh. */
int obrwWallpaperOpt_setWallpaperWithFeh(const char *dirPath,
                                         const char *wpToSet) {
    char *sysCmd;
    const char *fehCmd;
    size_t sysCmdLen = 0;

    if (NULL == wpToSet) {
        obrwLogger_error("No wallpaper given to set.");

        return SET_WALLPAPER_ERROR_NO_WALLPAPER_GIVEN;
    }

    // feh command to set a wallpaper over full display size
    //'feh --bg-scale /wonderfully/canonical/file.name'
    // Chars   01234567890 1234     --> 14 chars
    // sysCmd = feh --bg-sc ale		--> 14 chars
    fehCmd = "feh --bg-scale \0";
    sysCmdLen = strlen(fehCmd) + strlen(dirPath) + strlen(wpToSet) + 1;

    sysCmd = (char *) malloc(sizeof(char) * sysCmdLen);

    if (NULL == sysCmd) {
        obrwLogger_error("Got no heap-space for feh-string.");
        return SET_WALLPAPER_ERROR_NO_HEAP_SPACE;
    }

    // TODO if one failure, free it!
    strncpy(sysCmd, fehCmd, strlen(fehCmd));
    strncat(sysCmd, dirPath, strlen(dirPath));
    strncat(sysCmd, wpToSet, strlen(wpToSet));

    char *logMsg = (char *) malloc((32 + strlen(sysCmd)) * sizeof(char));
    sprintf(logMsg, "Try to set wallpaper via: <%s>.", sysCmd);
    obrwLogger_debug(logMsg);
    obrwUtils_freeCString(&logMsg);

    // SHELL
    system(sysCmd);

    obrwUtils_freeCString(&sysCmd);

    return SET_WALLPAPER_OK;
}

// TODO
// do it nice, not so dirty
/** Free all used allocated heap-memory (if used). */
void obrwWallpaperOpt_freeLocalsToClose(void) {
    if (wallpaperNames) {
        size_t i = 0;

        while (i < wallpaperNamesLength) {
            // TODO
            free(wallpaperNames[i]);
            wallpaperNames[i] = NULL;
            i++;
        }

        // TODO
        // free char** wallpaperNames
        //---------------------------------
        // free( &wallpaperNames );
        // wallpaperNames = NULL;

        wallpaperNamesLength = -1;
    }
}
