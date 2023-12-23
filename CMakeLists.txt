cmake_minimum_required(VERSION 3.15)
project(obrw)

set(CMAKE_C_STANDARD 99)

add_executable(obrw src/obrw_main.c tests/obrw_configTest.h tests/obrw_configTest.c
        src/obrw_chk_externals.h)
set (SOURCE_FILES ./src/*.c)