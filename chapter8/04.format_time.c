//
// Created by helisi on 2022/11/21.
//
#include "include/io_utils.h"
#include "include/time_utils.h"

int main() {
    // 格式化时间
    time_t current_time;
    current_time = time(NULL);

    struct tm *calender = localtime(&current_time);

    // 使用共享内存 线程不安全
    puts(asctime(calender));
    puts(ctime(&current_time));

    // 在栈中声明一块空间 没有线程安全问题
    char current_time_s[20];
    size_t size = strftime(current_time_s, 20, "%Y-%m-%d %H:%M:%S", calender);
    PRINT_INT(size);
    puts(current_time_s);

    size = strftime(current_time_s, 20, "%Y%m%d%H%M%S", calender);
    time_t current_time_millisecond = TimeInMillisecond();
    sprintf(current_time_s + 14, "%03d", current_time_millisecond);
    puts(current_time_s);

    return 0;
}