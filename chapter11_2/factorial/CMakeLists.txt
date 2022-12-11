cmake_minimum_required(VERSION 3.10.2)
project(fatorial C)

set(CMAKE_C_STANDARD 11)

# 静态链接库
add_library(factorial STATIC
        factorial.c)