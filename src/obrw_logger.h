/*
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_file.h
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
 * It is provided "as is" without express or implied warranty.
 *
 */

#ifndef OBRW_LOGGER_H
#define OBRW_LOGGER_H

#define TRUE 1
#define FALSE 0

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char* SUCCESS_TAG;
static const char* INFO_TAG;
static const char* WARNING_TAG;
static const char* DEBUG_TAG;
static const char* ERROR_TAG;

static void obrwLogger_success(const char* message);
static void obrwLogger_info(const char* message);
static void obrwLogger_warning(const char* message);
static void obrwLogger_debug(const char* message);
static void obrwLogger_debugSystem(const char* message);
static void obrwLogger_error(const char* message);

/**
 * Prints a multi line log message to stdout.
 *
 * @param tag The debug tag
 * @param messageLines The lines to print (separation via newline).
 */
static void obrwLogger_logMultiLine(const char* tag, const char* messageLines);

/**
 * Returns if the given tag is known.
 *
 * @param tag The debug tag
 * @return <code>TRUE</code> if the tag is known, otherwise <code>FALSE</code>.
 */
static int isTagKnown(const char* tag);

/**
 * Bla bla
 *
 * \return Nothing, it's void.
 */
static void obrwLogger_log(const char* tag, const char* message);


#endif //OBRW_LOGGER_H