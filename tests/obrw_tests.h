//
// Created by deeagle on 4/11/20.
//

#ifndef OBRW_OBRW_TESTS_H
#define OBRW_OBRW_TESTS_H

#include "../src/obrw_main.h"
#include "obrw_configTest.c"
#include "obrw_loggerTest.c"
#include "obrw_stringTest.c"

#define obrwTests_main main

int obrwTests_main(int argc, char **argv);
void obrwTests_runAll();

#endif  // OBRW_OBRW_TESTS_H
