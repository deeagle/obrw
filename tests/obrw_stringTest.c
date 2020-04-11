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