cmake_minimum_required(VERSION 3.21)
project(smol_utf8 C)

# Project settings and setup
set(CMAKE_C_STANDARD 17)
include(cmake/FetchCMocka.cmake)
add_definitions("-Wall" "-g")

# Sources and headers
set(SMOL_UTF8_HEADERS utf8.h)
set(SMOL_UTF8_SOURCES utf8.c)

# Library building
add_library(smol_utf8  ${SMOL_UTF8_HEADERS} ${SMOL_UTF8_SOURCES})

# Testing
add_executable(utf8_test ${SMOL_UTF8_HEADERS} ${SMOL_UTF8_SOURCES} utf8_test.c)
target_compile_features(utf8_test PRIVATE c_std_99)
target_link_libraries(utf8_test PRIVATE cmocka-static)

enable_testing()
add_test(NAME utf8_test COMMAND utf8_test)