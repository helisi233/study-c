cmake_minimum_required(VERSION 3.14)

project(study-c)

set(CMAKE_C_STANDARD 11)

# 导入宏文件时可以不需要再写路径
# include_directories("chapter3/include")

add_executable(study-c chapter5/include/Print_Utils.h chapter5/05.lvalue_rvalue.c)

#target_compile_definitions(study-c PUBLIC DEBUG)