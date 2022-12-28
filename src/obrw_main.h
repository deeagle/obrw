/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_main.h
 *
 * \brief The file includes the main-method of the tool. Also there is an
 * method to free all used allocated variables.
 */
#ifndef OBRW_MAIN_H
#define OBRW_MAIN_H

#define OBRW_EXTERNAL_TOOLS_OK 0
#define OBRW_EXTERNAL_TOOLS_ERROR (-1)

#include <stdio.h>
#include <stdlib.h>

#include "obrw_chk_externals.c"
#include "obrw_config.c"
#include "obrw_factory.c"
#include "obrw_logger.c"
#include "obrw_wallpaper_opt.c"

/** Command line param to set the log level. */
static const char *CLI_ARGUMENT_LOG_LEVEL = "--log-level=";
/** Command line param to call the help. */
static const char *CLI_HELP = "--help";
/** Helper constant to show help only (if called). */
static int IS_USER_CALLED_HELP = FALSE;
/** Command line param to call the version. */
static const char *CLI_VERSION = "--version";
/** Helper constant to show version only (if called). */
static int IS_USER_CALLED_VERSION = FALSE;
/** App version */
static const char *APP_VERSION = "0.4.0-SNAPSHOT";

/**
 * The main-method, which starts the obrw-process.
 *
 * \return If all is good, the process ends with EXIT_SUCCESS. Any kind of error
 * the program returns EXIT_FAILURE. \retval EXIT_SUCCESS all good. \retval
 * EXIT_FAILURE any kind of error.
 */
int main();

/**
 * Method to handle the command line arguments centralized.
 *
 * @param argc The given argument count.
 * @param argv An char array with the given arguments.
 */
void obrwMain_handleCommandLineArguments(const int argc, const char **argv);

/**
 * Prints the help to stdout.
 */
void obrwMain_printHelp();

/**
 * Prints the version to stdout.
 */
void obrwMain_printVersion();

/**
 * Free all used allocated heap-memory (if used, to use before program ends ->
 * success and fail).
 */
void freeAllToClose(void);

#endif  // OBRW_MAIN_H
