/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_string.c
 *
 * URL: http://deeagle.de
 *
 * Copyright (c) 2007-2010 Martin Kock <code@deeagle.de>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.\n\n\n
 *
 *
 * \file obrw_string.c
 *
 * \brief The file includes the special cstring-methods for the tool obrw.
 *
 */

#include "obrw_string.h"

/** Concatenates two cstrings to one cstring. */
char *obrwString_2CStringsTo1(const char *str1, const char *str2) {
    char *ptr = NULL;

    if (str1 != NULL && str2 != NULL) {
        size_t len = strlen(str1) + strlen(str2) + 1;
        ptr = (char *) malloc(sizeof(char) * len);

        // check if ptr exist because malloc allocs on heap-space
        // and it can fail.
        if (ptr) {
            strncpy(ptr, str1, strlen(str1) + 1);
            strncat(ptr, str2, strlen(str2) + 1);
        }
    }

    return ptr;
}

char *obrwString_parseConfigFileFor(const char *line) {
    char *parsedStr = NULL;
    char *strPtr = NULL;
    const char valueSeparator = '"';

    if (line != NULL) {
        if (obrwString_getCountOfChar(line, valueSeparator) >= 2) {
            // find the first " (DEZ = 34) in the cstring,
            // do a copy and deletes the second " at the end of the line.
            if ((strPtr = strchr(line, (int) valueSeparator)) != NULL) {
                size_t len = strlen(strPtr);
                parsedStr = (char *) malloc(sizeof(char) * len);

                strPtr++;
                if (parsedStr) {
                    const size_t lenToCopyWithoutClosingQuotationMark =
                            (strlen(strPtr) - 1);
                    memset(parsedStr, '\0', sizeof(char) * len);
                    strncat(parsedStr, strPtr,
                            lenToCopyWithoutClosingQuotationMark);

                    char *logMsg =
                            (char *) malloc((20 + strlen(parsedStr)) * sizeof(char));
                    sprintf(logMsg, "Parsed string is <%s>.", parsedStr);
                    obrwLogger_info(logMsg);
                    obrwUtils_freeCString(logMsg);
                } else {
                    obrwLogger_error("No memory (heap) avaiable!");
                    // return NULL;
                }
            } else {
                char *logMsg =
                        (char *) malloc((33 + strlen(line)) * sizeof(char));
                sprintf(logMsg, "Parsed string <%s> (return NULL).", line);
                obrwLogger_debug(logMsg);
                obrwUtils_freeCString(logMsg);
                // return NULL;
            }
        }
    }

    return parsedStr;
}

int obrwString_getCountOfChar(const char *line, const char character) {
    int count = 0;

    if (line != NULL && character != '\0') {
        for (int i = 0; line[i] != '\0'; ++i) {
            if (character == line[i]) {
                ++count;
            }
        }
    }
    // else: NULL is 0 and so it is the same like the result zero, but readable

    return count;
}
