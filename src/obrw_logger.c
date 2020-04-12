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

static void obrwLogger_debugSystem(const char* message)
{
    obrwLogger_log(DEBUG_TAG, message);
}

static void obrwLogger_error(const char* message)
{
    obrwLogger_log(ERROR_TAG, message);
}

static void obrwLogger_logMultiLine(const char *tag, const char *messageLines)
{
    assert(tag != NULL);
    assert(strlen(tag) > 0);
    assert(messageLines != NULL);
    assert(strlen(messageLines) > 0);
    assert(isTagKnown(tag) == TRUE);

    const int lineBufferSize = 1024;
    char lineBuffer[lineBufferSize];
    int lineStartsIndex = 0;
    int lineLength = 0;
    int messageLineCharIndex = 0;

    // set the lineBuffer
    memset(lineBuffer, '\0', sizeof(char) * lineBufferSize);

    while (messageLines[messageLineCharIndex] != '\0')
    {
        if (messageLines[messageLineCharIndex] == '\n')
        {
            strncat(lineBuffer, (messageLines + lineStartsIndex), lineLength);
            obrwLogger_log(tag, lineBuffer);
            // reset the lineBuffer
            memset(lineBuffer, '\0', sizeof(char) * lineBufferSize);
            lineLength = 0;
            lineStartsIndex = messageLineCharIndex + 1;
        }
        else
        {
            lineLength++;
        }
        messageLineCharIndex++;
    }
}

static int isTagKnown(const char *tag)
{
    assert(tag != NULL);

    if (0 == strcmp(tag, SUCCESS_TAG) || 0 == strcmp(tag, INFO_TAG) || 0 == strcmp(tag, WARNING_TAG) ||
        0 == strcmp(tag, DEBUG_TAG) || 0 == strcmp(tag, ERROR_TAG))
    {
        return TRUE;
    }

    return FALSE;
}

/**
 * https://stackoverflow.com/questions/6508461/logging-library-for-c
 */
static void 
obrwLogger_log(const char* tag, const char* message)
{
    assert(tag != NULL);
    assert(strlen(tag) > 0);
    assert(message != NULL);
    assert(strlen(message) > 0);
    assert(isTagKnown(tag) == TRUE);

   printf("[%s] %s\n", tag, message);
}
