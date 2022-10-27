/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_chk_externals.h
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_logger.h
 */

#ifndef OBRW_LOGGER_H
#define OBRW_LOGGER_H

#define TRUE 1
#define FALSE 0

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** The used log level. */
static int LOG_LEVEL = 0;
/** The tag to log. */
static const char *SUCCESS_TAG = " OK \0";
/** The command line value to activate this mode. */
static const char *SUCCESS_CLI_VALUE = "SUCCESS\0";
/** The internal log level. */
static const int SUCCESS_LOG_LEVEL = 0;
/** The tag to log. */
static const char *INFO_TAG = "INFO\0";
/** The command line value to activate this mode. */
static const char *INFO_CLI_VALUE = "INFO\0";
/** The internal log level. */
static const int INFO_LOG_LEVEL = 1;
/** The tag to log. */
static const char *WARNING_TAG = "WARN\0";
/** The command line value to activate this mode. */
static const char *WARNING_CLI_VALUE = "WARNING\0";
/** The internal log level. */
static const int WARNING_LOG_LEVEL = 2;
/** The tag to log. */
static const char *DEBUG_TAG = "DEBG\0";
/** The command line value to activate this mode. */
static const char *DEBUG_CLI_VALUE = "DEBUG\0";
/** The internal log level. */
static const int DEBUG_LOG_LEVEL = 3;
/** The command line value to activate this mode. */
static const char *DEBUG_SYSTEM_CLI_VALUE = "SYSTEM\0";
/** The tag to log. */
static const char *DEBUG_SYSTEM_TAG = "DSYS\0";
/** The internal log level. */
static const int DEBUG_SYSTEM_LOG_LEVEL = 4;
/** The tag to log. */
static const char *ERROR_TAG = "ERR!\0";
/** The command line value to activate this mode. */
static const char *ERROR_CLI_VALUE = "ERROR\0";
/** The internal log level. */
static const int ERROR_LOG_LEVEL = 0;

/** The highest internal log level value. */
static const int OBRW_LOGGER_HIGHEST_NUMBER_FOR_LOG_LEVEL = 4;
/** The max length of the command line string values. */
static const int OBRW_LOGGER_STR_LEN_OF_LONGEST_CLI_PARAM = 7;

/** Logs successful messages, depends on <code>LOG_LEVEL</code>. */
static void obrwLogger_success(const char *message);

/** Logs info messages, depends on <code>LOG_LEVEL</code>. */
static void obrwLogger_info(const char *message);

/** Logs warning messages, depends on <code>LOG_LEVEL</code>. */
static void obrwLogger_warning(const char *message);

/** Logs debug messages, depends on <code>LOG_LEVEL</code>. */
static void obrwLogger_debug(const char *message);

/** Logs system debugs, depends on <code>LOG_LEVEL</code>. */
static void obrwLogger_debugSystem(const char *message);

/** Logs error messages. */
static void obrwLogger_error(const char *message);

/**
 * Returns the internal log level identified by given tag.
 *
 * @param tag The internal log tag.
 * @return The depending internal log level.
 */
static int obrwLogger_getLogLevelByLogTag(const char *tag);

/**
 * Logs the internal used <code>LOG_LEVEL</code> depending on the log level.
 */
static void obrwLogger_printLogLevel();

/**
 * Sets the internal <code>LOG_LEVEL</code> by the given command line value.
 *
 * @param cliLogLevelValue The command line value for a log level.
 * @return <code>TRUE</code> if the command line value is known, otherwise
 * <code>FALSE</code>.
 */
static int obrwLogger_setLogLevelByCliValue(const char *cliLogLevelValue);

/**
 * Set the internal <code>LOG_LEVEL</code> by given log level.
 *
 * @param logLevel The log level to set.
 */
static void obrwLogger_setLogLevelByLevel(const int logLevel);

/**
 * Prints a multi line log message to stdout.
 *
 * @param tag The debug tag
 * @param messageLines The lines to print (separation via newline).
 */
static void obrwLogger_logMultiLine(const char *tag, const char *messageLines);

/**
 * Returns the acceptance of a given command line log level argument.
 *
 * @param cliLogLevelArgument The command line argument to validate.
 * @return <code>TRUE</code> if the command line value is known, otherwise
 * <code>FALSE</code>.
 */
static int obrwLogger_isCliParamValueKnown(const char *cliLogLevelArgument);

/**
 * Returns if the given tag is known.
 *
 * @param tag The debug tag
 * @return <code>TRUE</code> if the tag is known, otherwise <code>FALSE</code>.
 */
static int obrwLogger_isTagKnown(const char *tag);

/**
 * Logs the given message for the given log tag.
 *
 * @param tag The internal used tag.
 * @param message The message to log.
 */
static void obrwLogger_log(const char *tag, const char *message);

#endif  // OBRW_LOGGER_H
