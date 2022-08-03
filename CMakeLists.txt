cmake_minimum_required(VERSION 3.14)

project(study-c)

set(CMAKE_C_STANDARD 11)

# 导入宏文件时可以不需要再写路径
# include_directories("chapter3/include")

add_executable(study-c chapter4/include/Print_Util.h chapter4/06.quick_sort.c)

#target_compile_definitions(study-c PUBLIC DEBUG)