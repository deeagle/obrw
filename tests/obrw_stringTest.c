//
// Created by deeagle on 4/11/20.
//
#include "obrw_stringTest.h"

/**
 * Include all test methods here.
 */
void obrw_stringTest_runAll()
{
    twoStringToOne_twoNullSrings_expectedNullResult();
    twoStringsToOne_twoEmptyStrings_returnEmtpyString();
    twoStringToOne_oneStringEmpty_expectedStringOneAsResult();
    twoStringToOne_oneStringEmpty_expectedStringTwoAsResult();
    twoStringToOne_twoStrings_expectedStringOneStringTwoAsResult();

    parseConfigFileFor_nullInput_expectedNullResult();
    parseConfigFileFor_withoutQuotationMark_expectedNullResult();
    parseConfigFileFor_quotationMarkOnly_expectedEmptyString();
    parseConfigFileFor_quotationMarkString_expectedString();
    parseConfigFileFor_quotationMarkStringInStringWithoutSpaces_expectedString();
    parseConfigFileFor_quotationMarkStringInStringWithSpaces_expectedString();
    parseConfigFileFor_quotationMarkStringWithSpacesInStringWithSpaces_expectedString();
    parseConfigFileFor_StringWithOneQuotationMarkStart_expectedNullResult();
    parseConfigFileFor_StringWithOneQuotationMarkEnd_expectedNullResult();
}

void twoStringToOne_twoNullSrings_expectedNullResult()
{
    printf("%s - twoNullSrings_expectedNullResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str1 = NULL;
    const char* str2 = NULL;
    const char* expected = NULL;
    char* result;

    result = obrwString_2CStringsTo1(str1, str2 );

    assert(result == NULL);
}

void twoStringsToOne_twoEmptyStrings_returnEmtpyString()
{
    printf("%s - twoEmptyStrings_returnEmptyString\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str1 = "\0";
    const char* str2 = "\0";
    const char* expected = "\0";
    char* result;

    result = obrwString_2CStringsTo1(str1, str2 );

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void twoStringToOne_oneStringEmpty_expectedStringOneAsResult()
{
    printf("%s - oneStringEmpty_expectedStringOneAsResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str1 = "Alpha12%\0";
    const char* str2 = "\0";
    const char* expected = "Alpha12%\0";
    char* result;

    result = obrwString_2CStringsTo1(str1, str2 );

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void twoStringToOne_oneStringEmpty_expectedStringTwoAsResult()
{
    printf("%s - oneStringEmpty_expectedStringTwoAsResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str1 = "\0";
    const char* str2 = "Alpha12%\0";
    const char* expected = "Alpha12%\0";
    char* result;

    result = obrwString_2CStringsTo1(str1, str2 );

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void twoStringToOne_twoStrings_expectedStringOneStringTwoAsResult()
{
    printf("%s - twoStrings_expectedStringOneStringTwoAsResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str1 = "Alpha12%";
    const char* str2 = "Beta13";
    const char* expected = "Alpha12%Beta13\0";
    char* result;

    result = obrwString_2CStringsTo1(str1, str2 );

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void parseConfigFileFor_nullInput_expectedNullResult()
{
    printf("%s - parseConfigFileFor_nullInput_expectedNullResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = NULL;
    const char* expected = NULL;
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result == NULL);
}

void parseConfigFileFor_withoutQuotationMark_expectedNullResult()
{
    printf("%s - parseConfigFileFor_withoutQuotationMark_expectedNullResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "test-String\0";
    const char* expected = NULL;
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result == NULL);
}

void parseConfigFileFor_quotationMarkOnly_expectedEmptyString()
{
    printf("%s - parseConfigFileFor_quotationMarkOnly_expectedEmptyString\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "\"\"\0";
    const char* expected = "\0";
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void parseConfigFileFor_quotationMarkString_expectedString()
{
    printf("%s - parseConfigFileFor_quotationMarkString_expectedString\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "\"Test-String\"\0";
    const char* expected = "Test-String\0";
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void parseConfigFileFor_quotationMarkStringInStringWithoutSpaces_expectedString()
{
    printf("%s - parseConfigFileFor_quotationMarkStringInStringWithoutSpaces_expectedString\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "key=\"value\"\0";
    const char* expected = "value\0";
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void parseConfigFileFor_quotationMarkStringInStringWithSpaces_expectedString()
{
    printf("%s - parseConfigFileFor_quotationMarkStringInStringWithSpaces_expectedString\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "key = \"value\"\0";
    const char* expected = "value\0";
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void parseConfigFileFor_quotationMarkStringWithSpacesInStringWithSpaces_expectedString()
{
    printf("%s - parseConfigFileFor_quotationMarkStringWithSpacesInStringWithSpaces_expectedString\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "key = \"nice value\"\0";
    const char* expected = "nice value\0";
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void parseConfigFileFor_StringWithOneQuotationMarkStart_expectedNullResult()
{
    printf("%s - parseConfigFileFor_StringWithOneQuotationMarkStart_expectedNullResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "key = \"value\0";
    const char* expected = NULL;
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result == NULL);
    printf("Result differs from expected value: %s != %s", result, expected);
}

void parseConfigFileFor_StringWithOneQuotationMarkEnd_expectedNullResult()
{
    printf("%s - parseConfigFileFor_StringWithOneQuotationMarkEnd_expectedNullResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "key = value\"\0";
    const char* expected = NULL;
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result == NULL);
    printf("Result differs from expected value: %s != %s", result, expected);
}