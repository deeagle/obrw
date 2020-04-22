//
// Created by deeagle on 4/22/20.
//

#ifndef OBRW_OBRW_LOGGERTEST_H
#define OBRW_OBRW_LOGGERTEST_H

#include <assert.h>
#include <stdio.h>
#include "../src/obrw_logger.h"

static const char* OBRW_LOGGERTEST_CLASS_NAME = "obrw_loggerTest\0";

void obrw_loggerTest_runAll();

void isCliParamValueKnown_emptyCliLogLevelValue_returnFalse();
void isCliParamValueKnown_successCliLogLevelValue_returnTrue();
void isCliParamValueKnown_infoCliLogLevelValue_returnTrue();
void isCliParamValueKnown_warningCliLogLevelValue_returnTrue();
void isCliParamValueKnown_debugCliLogLevelValue_returnTrue();
void isCliParamValueKnown_debugSystemCliLogLevelValue_returnTrue();
void isCliParamValueKnown_errorCliLogLevelValue_returnTrue();

void setLogLevelByCliValue_emptyTag_returnFalse();
void setLogLevelByCliValue_successTag_returnTrue();
void setLogLevelByCliValue_infoTag_returnTrue();
void setLogLevelByCliValue_warningTag_returnTrue();
void setLogLevelByCliValue_debugTag_returnTrue();
void setLogLevelByCliValue_debugSystemTag_returnTrue();
void setLogLevelByCliValue_errorTag_returnTrue();

#endif //OBRW_OBRW_LOGGERTEST_H
