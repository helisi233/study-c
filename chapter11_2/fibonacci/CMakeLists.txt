cmake_minimum_required(VERSION 3.10.2)
project(fibonacci C)

set(CMAKE_C_STANDARD 11)

# WINDOWS环境需要引入库
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif(WIN32)

# 动态链接库
add_library(fibonacci SHARED
        fibonacci.c)

# 解决动态链接库路径问题
# 把可执行程序和动态链接库install一起
# RUNTIME 运行时需要用到的东西 windows中的exe和dll文件
# LIBRARY 运行时需要用到的东西 linux中的so文件
# ARCHIVE 运行时需要用到的东西 因入库的位置
install(TARGETS fibonacci
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)