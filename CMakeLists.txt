cmake_minimum_required(VERSION 3.14)

project(study-c)

set(CMAKE_C_STANDARD 11)

add_executable(study-c chapter10/include/io_utils.h chapter10/tinycthread/include/tinycthread.h chapter10/tinycthread/tinycthread.c chapter10/Code09.callback.c)