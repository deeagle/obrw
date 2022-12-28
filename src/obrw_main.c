/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_main.c
 *
 * \brief The file includes the main-method of the tool obrw. Also there is an
 * method to free all used allocated variables.
 */
#include "obrw_main.h"

/** The main-method, which starts the obrw-process. */
int main(int argc, char **argv) {
    obrwMain_handleCommandLineArguments(argc, (const char **) argv);
    if (IS_USER_CALLED_HELP) {
        obrwMain_printHelp(argv[0]);
        return EXIT_SUCCESS;
    }

    if (IS_USER_CALLED_VERSION) {
        obrwMain_printVersion();
        return EXIT_SUCCESS;
    }

    obrwLogger_printLogLevel();

    // start
    obrwUtils_setRandomCounterToZero();

    int isFehInstalled = obrwChkExt_isFehOnSystem();
    if (isFehInstalled != FEH_EXIST_AND_EXEC) {
        if (isFehInstalled == FEH_NOT_EXIST) {
            obrwLogger_error("Feh is not installed!");
        }

        if (isFehInstalled == FEH_NOT_EXEC) {
            obrwLogger_error("Feh is not executable!");
        }

        freeAllToClose();

        return EXIT_FAILURE;
    }

    obrwLogger_success("Dependencies successfully checked.");

    if (obrwConfig_readConfigFile() /* == EXIT_FAILURE */) {
        freeAllToClose();
        obrwLogger_error("Found error in config file!");
        return EXIT_FAILURE;
    }

    obrwLogger_success("Config file successfully checked.");

    struct wallpaper usedWallpaperItem = obrwFactory_getWallpaperItem();

    if (obrwWallpaperOpt_readDirAndSetWallpaper(
            obrwConfig_getWallpaperDir(),
            &usedWallpaperItem) /* == EXIT_FAILURE */) {
        freeAllToClose();
        obrwLogger_error("Wallpaper options error!");
    }

    obrwLogger_success("Setting wallpaper successfully handled.");

    if (obrwConfig_writeSettingsToConfigFile(
            &usedWallpaperItem) /* == EXIT_FAILURE */) {
        freeAllToClose();
        obrwLogger_error("Wallpaper write error!");
    }

    obrwLogger_success("Writing history successfully to file.");

    // before exit free() local globs
    freeAllToClose();

    obrwLogger_success("OBRW successfully finished.");

    return EXIT_SUCCESS;
}

void obrwMain_handleCommandLineArguments(const int argc, const char **argv) {
    // given arguments
    for (int i = 0; i < argc; i++) {
        if (strlen(argv[i]) == strlen(CLI_HELP)) {
            if (0 == strcmp(argv[i], CLI_HELP)) {
                IS_USER_CALLED_HELP = TRUE;
                break;
            }
        }

        if (strlen(argv[i]) == strlen(CLI_VERSION)) {
            if (0 == strcmp(argv[i], CLI_VERSION)) {
                IS_USER_CALLED_VERSION = TRUE;
                break;
            }
        }

        // value of argv must be greater than tag because of the delivered
        // value!
        if (strlen(argv[i]) > strlen(CLI_ARGUMENT_LOG_LEVEL)) {
            if (0 == strncmp(argv[i], CLI_ARGUMENT_LOG_LEVEL,
                             strlen(CLI_ARGUMENT_LOG_LEVEL))) {
                // use the longest entry for malloc size
                char *levelString = (char *) malloc(
                        OBRW_LOGGER_STR_LEN_OF_LONGEST_CLI_PARAM * sizeof(char));
                strncpy(levelString, argv[i] + strlen("--log-level="),
                        OBRW_LOGGER_STR_LEN_OF_LONGEST_CLI_PARAM);
                obrwLogger_setLogLevelByCliValue(levelString);
            }
        }
    }
}

void obrwMain_printHelp(const char *name) {
    printf("OBRW is OpenBoxRandomWallpaper, version %s\n", APP_VERSION);
    printf("Usage: %s [OPTION]\n", name);
    printf("Sets a randomized wallpaper from a given directory.\n");
    printf("\n");
    printf("  --log-level=<param>\tSupported params are:\n");
    printf("  \t\t\t  SUCCESS, ERROR (default)\n");
    printf("  \t\t\t  INFO\n");
    printf("  \t\t\t  WARNING\n");
    printf("  \t\t\t  DEBUG\n");
    printf("  \t\t\t  SYSTEM\n");
    printf("  --version\t\tPrints the version.\n");
    printf("  --help\t\tPrints this help.\n");
}

void obrwMain_printVersion() { printf("obrw version %s\n", APP_VERSION); }

/** Free all used allocated heap-memory (if used) (to use before program ends).
 */
void freeAllToClose(void) {
    obrwConfig_freeLocalsToClose();
    obrwWallpaperOpt_freeLocalsToClose();
}
