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

void getCountOfChar_nullInputs_expectedNullResult();
void getCountOfChar_nullStringAndSymbol_expectedResultIsZero();
void getCountOfChar_emptyStringAndSymbol_expectedResultIsZero();
void getCountOfChar_stringWithoutSymbolAndSymbol_expectedResultIsZero();
void getCountOfChar_stringWithOneSymbolAndSymbol_expectedResultIsOne();
void getCountOfChar_stringWithTwoSymbolAndSymbol_expectedResultIsTwo();
void getCountOfChar_stringWithThreeSymbolAndSymbol_expectedResultIsThree();
void getCountOfChar_stringWithTwoSymbolsOnlyAndSymbol_expectedResultIsTwo();

void parseConfigFileFor_nullInput_expectedNullResult();
void parseConfigFileFor_withoutQuotationMark_expectedNullResult();
void parseConfigFileFor_quotationMarkOnly_expectedEmptyString();
void parseConfigFileFor_quotationMarkString_expectedString();
void parseConfigFileFor_quotationMarkStringInStringWithoutSpaces_expectedString();
void parseConfigFileFor_quotationMarkStringInStringWithSpaces_expectedString();
void parseConfigFileFor_quotationMarkStringWithSpacesInStringWithSpaces_expectedString();
void parseConfigFileFor_StringWithOneQuotationMarkStart_expectedNullResult();
void parseConfigFileFor_StringWithOneQuotationMarkEnd_expectedNullResult();
void parseConfigFileFor_possibleWallpaperDirectorySetStringOfUser_expectedPathStringResult();

#endif //OBRW_OBRW_STRINGTEST_H
