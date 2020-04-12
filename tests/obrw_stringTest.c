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

    getCountOfChar_nullInputs_expectedNullResult();
    getCountOfChar_nullStringAndSymbol_expectedResultIsZero();
    getCountOfChar_emptyStringAndSymbol_expectedResultIsZero();
    getCountOfChar_stringWithoutSymbolAndSymbol_expectedResultIsZero();
    getCountOfChar_stringWithOneSymbolAndSymbol_expectedResultIsOne();
    getCountOfChar_stringWithTwoSymbolAndSymbol_expectedResultIsTwo();
    getCountOfChar_stringWithThreeSymbolAndSymbol_expectedResultIsThree();
    getCountOfChar_stringWithTwoSymbolsOnlyAndSymbol_expectedResultIsTwo();

    parseConfigFileFor_nullInput_expectedNullResult();
    parseConfigFileFor_withoutQuotationMark_expectedNullResult();
    parseConfigFileFor_quotationMarkOnly_expectedEmptyString();
    parseConfigFileFor_quotationMarkString_expectedString();
    parseConfigFileFor_quotationMarkStringInStringWithoutSpaces_expectedString();
    parseConfigFileFor_quotationMarkStringInStringWithSpaces_expectedString();
    parseConfigFileFor_quotationMarkStringWithSpacesInStringWithSpaces_expectedString();
    parseConfigFileFor_StringWithOneQuotationMarkStart_expectedNullResult();
    parseConfigFileFor_StringWithOneQuotationMarkEnd_expectedNullResult();
    parseConfigFileFor_possibleWallpaperDirectorySetStringOfUser_expectedPathStringResult();

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
}

void parseConfigFileFor_StringWithOneQuotationMarkEnd_expectedNullResult()
{
    printf("%s - parseConfigFileFor_StringWithOneQuotationMarkEnd_expectedNullResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "key = value\"\0";
    const char* expected = NULL;
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result == NULL);
}

/**
 * Tests a possible setted wallpaper path.
 * <p>
 * I include it because of strange string behaviours.
 * After a compare of <code>strncpy</codo> and <code>strncat</code>, it seems, that <code>strncat</code> works correctly.
 * After a nice format of the compare, both work like expected ... -> :?
 * <p>
 * Setup was:
 * - Both with reset destination via memset
 * - same const source
 * - same length to copy
 * - results
 *   - strncpy -> /home/user/.config/wallpaper-directory/1024x768/>.
 *   - strncat -> /home/user/.config/wallpaper-directory/1024x768/
 */
void parseConfigFileFor_possibleWallpaperDirectorySetStringOfUser_expectedPathStringResult()
{
    printf("%s - parseConfigFileFor_possibleWallpaperDirectorySetStringOfUser_expectedPathStringResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* str = "wpDir = \"/home/user/.config/wallpaper-directory/1024x768/\"";
    const char* expected = "/home/user/.config/wallpaper-directory/1024x768/";
    char* result;

    result = obrwString_parseConfigFileFor(str);

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}


void getCountOfChar_nullInputs_expectedNullResult()
{
    printf("%s - getCountOfChar_nullInputs_expectedNullResult\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = NULL;
    // there is no NULL char
    const char searchFor = '\0';
    int expected = 0;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}

void getCountOfChar_nullStringAndSymbol_expectedResultIsZero()
{
    printf("%s - getCountOfChar_nullStringAndSymbol_expectedResultIsZero\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = NULL;
    const char searchFor = '"';
    int expected = 0;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}

void getCountOfChar_emptyStringAndSymbol_expectedResultIsZero()
{
    printf("%s - getCountOfChar_emptyStringAndSymbol_expectedResultIsZero\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = "\0";
    const char searchFor = '"';
    int expected = 0;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}

void getCountOfChar_stringWithoutSymbolAndSymbol_expectedResultIsZero()
{
    printf("%s - getCountOfChar_stringWithoutSymbolAndSymbol_expectedResultIsZero\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = "nice test-string\0";
    const char searchFor = '"';
    int expected = 0;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}

void getCountOfChar_stringWithOneSymbolAndSymbol_expectedResultIsOne()
{
    printf("%s - getCountOfChar_stringWithOneSymbolAndSymbol_expectedResultIsOne\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = "nice \" test-string\0";
    const char searchFor = '"';
    int expected = 1;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}

void getCountOfChar_stringWithTwoSymbolAndSymbol_expectedResultIsTwo()
{
    printf("%s - getCountOfChar_stringWithTwoSymbolAndSymbol_expectedResultIsTwo\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = "nice \"test-string\"\0";
    const char searchFor = '"';
    int expected = 2;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}

void getCountOfChar_stringWithThreeSymbolAndSymbol_expectedResultIsThree()
{
    printf("%s - getCountOfChar_stringWithThreeSymbolAndSymbol_expectedResultIsThree\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = "nice \" test\"-\"string\0";
    const char searchFor = '"';
    int expected = 3;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}

void getCountOfChar_stringWithTwoSymbolsOnlyAndSymbol_expectedResultIsTwo()
{
    printf("%s - getCountOfChar_stringWithTwoSymbolsOnlyAndSymbol_expectedResultIsTwo\n", OBRW_STRINGTEST_CLASS_NAME);

    const char* line = "\"\"\0";
    const char searchFor = '"';
    int expected = 2;
    int result;

    result = obrwString_getCountOfChar(line, searchFor);

    assert(expected == result);
}