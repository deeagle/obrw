//
// Created by deeagle on 4/11/20.
//
#include "obrw_tests.h"

/**
 * The main function.
 *
 * @return The runtime stage.
 */
int main() {
    time_t startTime = time(NULL);

    printf("Start tests.\n\n");
    runAll();

    time_t finishTime = time(NULL);

    printf("\nFinishes all tests successfully.\n");
    printf("Tests run about %.6f\n", (double)(finishTime - startTime));

    return EXIT_SUCCESS;
}

/**
 * Add all class test caller methods here.
 */
void runAll() {
    obrw_configTest_runAll();
    obrw_loggerTest_runAll();
    obrw_stringTest_runAll();
}
