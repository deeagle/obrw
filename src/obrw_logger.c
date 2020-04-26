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

static int LOG_LEVEL = 0;

static const char* SUCCESS_TAG = " OK \0";
static const char* SUCCESS_CLI_VALUE = "SUCCESS\0";
static const int SUCCESS_LOG_LEVEL = 0;
static const char* INFO_TAG = "INFO\0";
static const char* INFO_CLI_VALUE = "INFO\0";
static const int INFO_LOG_LEVEL = 1;
static const char* WARNING_TAG = "WARN\0";
static const char* WARNING_CLI_VALUE = "WARNING\0";
static const int WARNING_LOG_LEVEL = 2;
static const char* DEBUG_TAG = "DEBG\0";
static const char* DEBUG_CLI_VALUE = "DEBUG\0";
static const int DEBUG_LOG_LEVEL = 3;
static const char* DEBUG_SYSTEM_CLI_VALUE = "SYSTEM\0";
static const char* DEBUG_SYSTEM_TAG = "DSYS\0";
static const int DEBUG_SYSTEM_LOG_LEVEL = 4;
static const char* ERROR_TAG = "ERR!\0";
static const char* ERROR_CLI_VALUE = "ERROR\0";
static const int ERROR_LOG_LEVEL = 0;

//TODO move into init function
static const int OBRW_LOGGER_HIGHEST_NUMBER_FOR_LOG_LEVEL = 4;
//TODO move into init function
static const int OBRW_LOGGER_STR_LEN_OF_LONGEST_CLI_PARAM = 7;

static int obrwLogger_setLogLevelByCliValue(const char *cliLogLevelValue)
{
    assert(cliLogLevelValue != NULL);

    if( obrwLogger_isCliParamValueKnown(cliLogLevelValue) )
    {
        if(0 == strcmp(SUCCESS_CLI_VALUE, cliLogLevelValue))
        {
            obrwLogger_setLogLevelByLevel(SUCCESS_LOG_LEVEL);
        }
        else if(0 == strcmp(INFO_CLI_VALUE, cliLogLevelValue))
        {
            obrwLogger_setLogLevelByLevel(INFO_LOG_LEVEL);
        }
        else if(0 == strcmp(WARNING_CLI_VALUE, cliLogLevelValue))
        {
            obrwLogger_setLogLevelByLevel(WARNING_LOG_LEVEL);
        }
        else if(0 == strcmp(DEBUG_CLI_VALUE, cliLogLevelValue))
        {
            obrwLogger_setLogLevelByLevel(DEBUG_LOG_LEVEL);
        }
        else if(0 == strcmp(DEBUG_SYSTEM_CLI_VALUE, cliLogLevelValue))
        {
            obrwLogger_setLogLevelByLevel(DEBUG_SYSTEM_LOG_LEVEL);
        }
        else if(0 == strcmp(ERROR_CLI_VALUE, cliLogLevelValue))
        {
            obrwLogger_setLogLevelByLevel(ERROR_LOG_LEVEL);
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void obrwLogger_setLogLevelByLevel(const int logLevel)
{
    assert(logLevel <= OBRW_LOGGER_HIGHEST_NUMBER_FOR_LOG_LEVEL);

    LOG_LEVEL = logLevel;
}

static void obrwLogger_success(const char* message)
{
    if(LOG_LEVEL >= SUCCESS_LOG_LEVEL)
    {
        obrwLogger_log(SUCCESS_TAG, message);
    }
}

static void obrwLogger_info(const char* message)
{
    if(LOG_LEVEL >= INFO_LOG_LEVEL)
    {
        obrwLogger_log(INFO_TAG, message);
    }
}

static void obrwLogger_warning(const char* message)
{
    if(LOG_LEVEL >= WARNING_LOG_LEVEL)
    {
        obrwLogger_log(WARNING_TAG, message);
    }
}

static void obrwLogger_debug(const char* message)
{
    if(LOG_LEVEL >= DEBUG_LOG_LEVEL)
    {
        obrwLogger_log(DEBUG_TAG, message);
    }
}

static void obrwLogger_debugSystem(const char* message)
{
    if(LOG_LEVEL >= DEBUG_SYSTEM_LOG_LEVEL)
    {
        obrwLogger_log(DEBUG_TAG, message);
    }
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
    assert(obrwLogger_isTagKnown(tag) == TRUE);

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

static int obrwLogger_isCliParamValueKnown(const char *cliLogLevelArgument)
{
    assert(cliLogLevelArgument != NULL);

    if(0 == strcmp(cliLogLevelArgument, SUCCESS_CLI_VALUE) || 0 == strcmp(cliLogLevelArgument, INFO_CLI_VALUE) ||
       0 == strcmp(cliLogLevelArgument, WARNING_CLI_VALUE) ||
       0 == strcmp(cliLogLevelArgument, DEBUG_CLI_VALUE) || 0 == strcmp(cliLogLevelArgument, DEBUG_SYSTEM_CLI_VALUE) ||
       0 == strcmp(cliLogLevelArgument, ERROR_CLI_VALUE))
    {
        return TRUE;
    }

    return FALSE;
}

static int obrwLogger_isTagKnown(const char *tag)
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
    assert(obrwLogger_isTagKnown(tag) == TRUE);

   printf("[%s] %s\n", tag, message);
}
