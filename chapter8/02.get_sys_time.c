//
// Created by helisi on 2022/11/20.
//
#include "include/io_utils.h"
#include "include/time_utils.h"
#include <time.h>

int main() {
    time_t current_time;
    // 获取系统时间 节省复制空间
    time(&current_time);
    PRINT_LONG(current_time);
    current_time = time(NULL);
    PRINT_LONG(current_time);
    PRINT_LONG(TimeInMillisecond());
    return 0;
}