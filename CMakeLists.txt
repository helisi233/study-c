cmake_minimum_required(VERSION 3.14)

project(study-c)

set(CMAKE_C_STANDARD 11)

add_executable(study-c chapter10/include/io_utils.h chapter11/mathutils/include/factorial.h chapter11/mathutils/include/fibonacci.h chapter11/Code04.library_with_cmake.c)