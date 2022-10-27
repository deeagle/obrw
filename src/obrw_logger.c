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

static int obrwLogger_setLogLevelByCliValue(const char *cliLogLevelValue) {
    assert(cliLogLevelValue != NULL);

    if (obrwLogger_isCliParamValueKnown(cliLogLevelValue)) {
        if (0 == strcmp(SUCCESS_CLI_VALUE, cliLogLevelValue)) {
            obrwLogger_setLogLevelByLevel(SUCCESS_LOG_LEVEL);
        } else if (0 == strcmp(INFO_CLI_VALUE, cliLogLevelValue)) {
            obrwLogger_setLogLevelByLevel(INFO_LOG_LEVEL);
        } else if (0 == strcmp(WARNING_CLI_VALUE, cliLogLevelValue)) {
            obrwLogger_setLogLevelByLevel(WARNING_LOG_LEVEL);
        } else if (0 == strcmp(DEBUG_CLI_VALUE, cliLogLevelValue)) {
            obrwLogger_setLogLevelByLevel(DEBUG_LOG_LEVEL);
        } else if (0 == strcmp(DEBUG_SYSTEM_CLI_VALUE, cliLogLevelValue)) {
            obrwLogger_setLogLevelByLevel(DEBUG_SYSTEM_LOG_LEVEL);
        } else if (0 == strcmp(ERROR_CLI_VALUE, cliLogLevelValue)) {
            obrwLogger_setLogLevelByLevel(ERROR_LOG_LEVEL);
        }

        return TRUE;
    } else {
        return FALSE;
    }
}

static void obrwLogger_setLogLevelByLevel(const int logLevel) {
    assert(logLevel <= OBRW_LOGGER_HIGHEST_NUMBER_FOR_LOG_LEVEL);

    LOG_LEVEL = logLevel;
}

static void obrwLogger_success(const char *message) {
    assert(message != NULL);
    assert(strlen(message) > 0);

    if (LOG_LEVEL >= SUCCESS_LOG_LEVEL) {
        obrwLogger_log(SUCCESS_TAG, message);
    }
}

static void obrwLogger_info(const char *message) {
    assert(message != NULL);
    assert(strlen(message) > 0);

    if (LOG_LEVEL >= INFO_LOG_LEVEL) {
        obrwLogger_log(INFO_TAG, message);
    }
}

static void obrwLogger_warning(const char *message) {
    assert(message != NULL);
    assert(strlen(message) > 0);

    if (LOG_LEVEL >= WARNING_LOG_LEVEL) {
        obrwLogger_log(WARNING_TAG, message);
    }
}

static void obrwLogger_debug(const char *message) {
    assert(message != NULL);
    assert(strlen(message) > 0);

    if (LOG_LEVEL >= DEBUG_LOG_LEVEL) {
        obrwLogger_log(DEBUG_TAG, message);
    }
}

static void obrwLogger_debugSystem(const char *message) {
    assert(message != NULL);
    assert(strlen(message) > 0);

    if (LOG_LEVEL >= DEBUG_SYSTEM_LOG_LEVEL) {
        obrwLogger_log(DEBUG_TAG, message);
    }
}

static void obrwLogger_error(const char *message) {
    assert(message != NULL);
    assert(strlen(message) > 0);

    obrwLogger_log(ERROR_TAG, message);
}

static void obrwLogger_logMultiLine(const char *tag, const char *messageLines) {
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

    while (messageLines[messageLineCharIndex] != '\0') {
        if (messageLines[messageLineCharIndex] == '\n') {
            strncat(lineBuffer, (messageLines + lineStartsIndex), lineLength);
            obrwLogger_log(tag, lineBuffer);
            // reset the lineBuffer
            memset(lineBuffer, '\0', sizeof(char) * lineBufferSize);
            lineLength = 0;
            lineStartsIndex = messageLineCharIndex + 1;
        } else {
            lineLength++;
        }
        messageLineCharIndex++;
    }
}

static int obrwLogger_getLogLevelByLogTag(const char *tag) {
    assert(tag != NULL);
    assert(strlen(tag) > 0);
    assert(obrwLogger_isTagKnown(tag) == TRUE);

    int logLevel = SUCCESS_LOG_LEVEL;

    if (0 == strcmp(SUCCESS_TAG, tag)) {
        logLevel = SUCCESS_LOG_LEVEL;
    } else if (0 == strcmp(INFO_TAG, tag)) {
        logLevel = INFO_LOG_LEVEL;
    } else if (0 == strcmp(WARNING_TAG, tag)) {
        logLevel = WARNING_LOG_LEVEL;
    } else if (0 == strcmp(DEBUG_TAG, tag)) {
        logLevel = DEBUG_LOG_LEVEL;
    } else if (0 == strcmp(DEBUG_SYSTEM_TAG, tag)) {
        logLevel = DEBUG_SYSTEM_LOG_LEVEL;
    } else if (0 == strcmp(ERROR_TAG, tag)) {
        logLevel = ERROR_LOG_LEVEL;
    }

    return logLevel;
}

static int obrwLogger_isCliParamValueKnown(const char *cliLogLevelArgument) {
    assert(cliLogLevelArgument != NULL);

    if (0 == strcmp(cliLogLevelArgument, SUCCESS_CLI_VALUE) ||
        0 == strcmp(cliLogLevelArgument, INFO_CLI_VALUE) ||
        0 == strcmp(cliLogLevelArgument, WARNING_CLI_VALUE) ||
        0 == strcmp(cliLogLevelArgument, DEBUG_CLI_VALUE) ||
        0 == strcmp(cliLogLevelArgument, DEBUG_SYSTEM_CLI_VALUE) ||
        0 == strcmp(cliLogLevelArgument, ERROR_CLI_VALUE)) {
        return TRUE;
    }

    return FALSE;
}

static int obrwLogger_isTagKnown(const char *tag) {
    assert(tag != NULL);

    if (0 == strcmp(tag, SUCCESS_TAG) || 0 == strcmp(tag, INFO_TAG) ||
        0 == strcmp(tag, WARNING_TAG) || 0 == strcmp(tag, DEBUG_TAG) ||
        0 == strcmp(tag, DEBUG_SYSTEM_CLI_VALUE) ||
        0 == strcmp(tag, ERROR_TAG)) {
        return TRUE;
    }

    return FALSE;
}

/**
 * https://stackoverflow.com/questions/6508461/logging-library-for-c
 */
static void obrwLogger_log(const char *tag, const char *message) {
    assert(tag != NULL);
    assert(strlen(tag) > 0);
    assert(message != NULL);
    assert(obrwLogger_isTagKnown(tag) == TRUE);

    if (LOG_LEVEL >= obrwLogger_getLogLevelByLogTag(tag)) {
        printf("[%s] %s\n", tag, message);
    }
}

static void obrwLogger_printLogLevel() {
    char *logMsg = (char *)malloc(21 * sizeof(char));
    sprintf(logMsg, "Used Log-Level is %d.", LOG_LEVEL);
    obrwLogger_info(logMsg);
    obrwUtils_freeCString(logMsg);
}
