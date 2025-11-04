cmake_minimum_required(VERSION 3.15)
project(PEECode C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

file(GLOB_RECURSE SRC_FILES src/*.c)
file(GLOB_RECURSE TEST_FILES test/*.c)

add_executable(pee_code main.c ${SRC_FILES} ${TEST_FILES})
