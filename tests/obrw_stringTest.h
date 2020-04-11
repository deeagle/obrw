//
// Created by deeagle on 4/11/20.
//

#ifndef OBRW_OBRW_STRINGTEST_H
#define OBRW_OBRW_STRINGTEST_H

#include <assert.h>
#include <stdio.h>
#include "../src/obrw_string.h"

static const char* OBRW_STRINGTEST_CLASS_NAME = "obrw_stringTest\0";

void obrw_stringTest_runAll();
void simpleTest();
void simpleClassTest();
void twoStringToOne_twoNullSrings_expectedNullResult();
void twoStringsToOne_twoEmptyStrings_returnEmtpyString();
void twoStringToOne_oneStringEmpty_expectedStringOneAsResult();
void twoStringToOne_oneStringEmpty_expectedStringTwoAsResult();
void twoStringToOne_twoStrings_expectedStringOneStringTwoAsResult();
void parseConfigFileFor_nullInput_expectedNullResult();
void parseConfigFileFor_withoutQuotationMark_expectedEmptyString();
void parseConfigFileFor_quotationMarkOnly_expectedEmptyString();
void parseConfigFileFor_quotianMarkString_expectedString();
void parseConfigFileFor_quotianMarkStringInStringWithoutSpaces_expectedString();
void parseConfigFileFor_quotianMarkStringInStringWithSpaces_expectedString();
void parseConfigFileFor_StringWithOneQuotianMarkStart_expectedEmptyString();
void parseConfigFileFor_StringWithOneQuotianMarkEnd_expectedEmptyString();

#endif //OBRW_OBRW_STRINGTEST_H
