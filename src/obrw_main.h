/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_main.h
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
 * \file obrw_main.h
 *
 * \brief The file includes the main-method of the tool obrw. Also there is an method to free all used alocated variables.
 *
 */

#ifndef OBRW_MAIN_H
#define OBRW_MAIN_H

#include <stdlib.h>
#include <stdio.h>
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

/**
 * The main-method, which starts the obrw-process.
 *
 * \return If all is good, the process ends with EXIT_SUCCESS. Any kind of error the programm returns EXIT_FAILURE.
 * \retval EXIT_SUCCESS all good.
 * \retval EXIT_FAILURE any kind of error.
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
 * Free all used allocated heap-memory (if used, to use before program ends -> success and fail).
 */
void freeAllToClose( void );

#endif //OBRW_MAIN_H
