/*
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_.c
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
#include "obrw_logger.h"

static const char* SUCCESS_TAG = " OK \0";
static const char* INFO_TAG = "INFO\0";
static const char* WARNING_TAG = "WARN\0";
static const char* DEBUG_TAG = "DEBG\0";
static const char* ERROR_TAG = "ERR!\0";

static void obrwLogger_success(const char* message)
{
    obrwLogger_log(SUCCESS_TAG, message);
}

static void obrwLogger_info(const char* message)
{
    obrwLogger_log(INFO_TAG, message);
}

static void obrwLogger_warning(const char* message)
{
    obrwLogger_log(WARNING_TAG, message);
}

static void obrwLogger_debug(const char* message)
{
    obrwLogger_log(DEBUG_TAG, message);
}

static void obrwLogger_error(const char* message)
{
    obrwLogger_log(ERROR_TAG, message);
}

/**
 * https://stackoverflow.com/questions/6508461/logging-library-for-c
 */
static void 
obrwLogger_log(const char* tag, const char* message)
{
   printf("[%s] %s\n", tag, message);
}
