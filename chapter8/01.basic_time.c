//
// Created by helisi on 2022/11/20.
//
#include "include/io_utils.h"
#include <stdlib.h>
#include <time.h>

#ifdef __UNIX__
    #include <sys/time.h>
#endif

int main() {
    time_t; // 从epoch开始计算的时间，绝对时间，不可读，与时区无关
    clock_t;    // 进程消耗CPU的时间，绝对时间，不可读，与时区无关
    struct tm;  // 月份从0开始 年从1900开始的时间差
    struct timespec;    // C11 秒和纳秒 如果环境支持C11直接使用这个就可以
    struct timeb;   // 毫秒
#ifdef __unix__
    struct timeval;
#endif

    return 0;
}