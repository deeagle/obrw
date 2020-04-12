cmake_minimum_required(VERSION 3.15)
project(obrw)

set(CMAKE_C_STANDARD 99)

add_executable(obrw src/obrw_main.c)
set (SOURCE_FILES ./src/*.c)