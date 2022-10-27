//
// Created by deeagle on 4/22/20.
//

#include "obrw_loggerTest.h"

const char* CLI_LOG_PARAM_SUCCESS = "SUCCESS\0";
const char* CLI_LOG_PARAM_INFO = "INFO\0";
const char* CLI_LOG_PARAM_WARNING = "WARNING\0";
const char* CLI_LOG_PARAM_DEBUG = "DEBUG\0";
const char* CLI_LOG_PARAM_SYSTEM = "SYSTEM\0";
const char* CLI_LOG_PARAM_ERROR = "ERROR\0";

void obrw_loggerTest_runAll() {
    isCliParamValueKnown_emptyCliLogLevelValue_returnFalse();
    isCliParamValueKnown_successCliLogLevelValue_returnTrue();
    isCliParamValueKnown_infoCliLogLevelValue_returnTrue();
    isCliParamValueKnown_warningCliLogLevelValue_returnTrue();
    isCliParamValueKnown_debugCliLogLevelValue_returnTrue();
    isCliParamValueKnown_debugSystemCliLogLevelValue_returnTrue();
    isCliParamValueKnown_errorCliLogLevelValue_returnTrue();

    setLogLevelByCliValue_emptyTag_returnFalse();
    setLogLevelByCliValue_successTag_returnTrue();
    setLogLevelByCliValue_infoTag_returnTrue();
    setLogLevelByCliValue_warningTag_returnTrue();
    setLogLevelByCliValue_debugTag_returnTrue();
    setLogLevelByCliValue_debugSystemTag_returnTrue();
    setLogLevelByCliValue_errorTag_returnTrue();
}

void isCliParamValueKnown_emptyCliLogLevelValue_returnFalse() {
    printf("%s - isCliParamValueKnown_emptyCliLogLevelValue_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* cliLogLevelValue = "";
    const int expected = FALSE;
    int result;

    result = obrwLogger_isCliParamValueKnown(cliLogLevelValue);

    assert(result == expected);
}

void isCliParamValueKnown_successCliLogLevelValue_returnTrue() {
    printf("%s - isCliParamValueKnown_successCliLogLevelValue_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* cliLogLevelValue = SUCCESS_CLI_VALUE;
    const int expected = TRUE;
    int result;

    result = obrwLogger_isCliParamValueKnown(cliLogLevelValue);

    assert(result == expected);
}

void isCliParamValueKnown_infoCliLogLevelValue_returnTrue() {
    printf("%s - isCliParamValueKnown_successCliLogLevelValue_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* cliLogLevelValue = INFO_CLI_VALUE;
    const int expected = TRUE;
    int result;

    result = obrwLogger_isCliParamValueKnown(cliLogLevelValue);

    assert(result == expected);
}

void isCliParamValueKnown_warningCliLogLevelValue_returnTrue() {
    printf("%s - isCliParamValueKnown_successCliLogLevelValue_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* cliLogLevelValue = WARNING_CLI_VALUE;
    const int expected = TRUE;
    int result;

    result = obrwLogger_isCliParamValueKnown(cliLogLevelValue);

    assert(result == expected);
}

void isCliParamValueKnown_debugCliLogLevelValue_returnTrue() {
    printf("%s - isCliParamValueKnown_successCliLogLevelValue_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* cliLogLevelValue = DEBUG_CLI_VALUE;
    const int expected = TRUE;
    int result;

    result = obrwLogger_isCliParamValueKnown(cliLogLevelValue);

    assert(result == expected);
}

void isCliParamValueKnown_debugSystemCliLogLevelValue_returnTrue() {
    printf("%s - isCliParamValueKnown_successCliLogLevelValue_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* cliLogLevelValue = DEBUG_SYSTEM_CLI_VALUE;
    const int expected = TRUE;
    int result;

    result = obrwLogger_isCliParamValueKnown(cliLogLevelValue);

    assert(result == expected);
}

void isCliParamValueKnown_errorCliLogLevelValue_returnTrue() {
    printf("%s - isCliParamValueKnown_successCliLogLevelValue_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* cliLogLevelValue = ERROR_CLI_VALUE;
    const int expected = TRUE;
    int result;

    result = obrwLogger_isCliParamValueKnown(cliLogLevelValue);

    assert(result == expected);
}

void setLogLevelByCliValue_emptyTag_returnFalse() {
    printf("%s - setLogLevelByCliValue_emptyTag_returnFalse\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* tag = "";
    const int expected = FALSE;
    int result;

    result = obrwLogger_setLogLevelByCliValue(tag);

    assert(result == expected);
}

void setLogLevelByCliValue_successTag_returnTrue() {
    printf("%s - setLogLevelByCliValue_successTag_returnTrue\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* tag = CLI_LOG_PARAM_SUCCESS;
    const int expected = TRUE;
    int result;

    result = obrwLogger_setLogLevelByCliValue(tag);

    assert(result == expected);
}

void setLogLevelByCliValue_infoTag_returnTrue() {
    printf("%s - setLogLevelByCliValue_infoTag_returnTrue\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* tag = CLI_LOG_PARAM_INFO;
    const int expected = TRUE;
    int result;

    result = obrwLogger_setLogLevelByCliValue(tag);

    assert(result == expected);
}

void setLogLevelByCliValue_warningTag_returnTrue() {
    printf("%s - setLogLevelByCliValue_warningTag_returnTrue\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* tag = CLI_LOG_PARAM_WARNING;
    const int expected = TRUE;
    int result;

    result = obrwLogger_setLogLevelByCliValue(tag);

    assert(result == expected);
}

void setLogLevelByCliValue_debugTag_returnTrue() {
    printf("%s - setLogLevelByCliValue_debugTag_returnTrue\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* tag = CLI_LOG_PARAM_DEBUG;
    const int expected = TRUE;
    int result;

    result = obrwLogger_setLogLevelByCliValue(tag);

    assert(result == expected);
}

void setLogLevelByCliValue_debugSystemTag_returnTrue() {
    printf("%s - setLogLevelByCliValue_systemTag_returnTrue\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* tag = CLI_LOG_PARAM_SYSTEM;
    const int expected = TRUE;
    int result;

    result = obrwLogger_setLogLevelByCliValue(tag);

    assert(result == expected);
}

void setLogLevelByCliValue_errorTag_returnTrue() {
    printf("%s - setLogLevelByCliValue_errorTag_returnTrue\n",
           OBRW_LOGGERTEST_CLASS_NAME);

    const char* tag = CLI_LOG_PARAM_ERROR;
    const int expected = TRUE;
    int result;

    result = obrwLogger_setLogLevelByCliValue(tag);

    assert(result == expected);
}
