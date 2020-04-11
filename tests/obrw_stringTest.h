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

#endif //OBRW_OBRW_STRINGTEST_H
