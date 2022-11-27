//
// Created by helisi on 2022/11/21.
//
#include "include/io_utils.h"
#include "include/time_utils.h"
#include <time.h>

int main() {
    // 获取日历时间
    time_t current_time;
    time(&current_time);
    struct tm *calender = localtime(&current_time);
    PRINT_INT(calender -> tm_year);
    PRINT_INT(calender -> tm_mon);
    PRINT_INT(calender -> tm_mday);
    PRINT_INT(calender -> tm_hour);
    PRINT_INT(calender -> tm_min);
    PRINT_INT(calender -> tm_sec);

    calender -> tm_sec = 70;
    // mktime会将tm结构体里面的内容规范化 比如进位
    time_t current_time2 = mktime(calender);

    // 根据格林威治时间转换 差8小时
    struct tm *g_calender = gmtime(&current_time);
    PRINT_INT(g_calender -> tm_year);
    PRINT_INT(g_calender -> tm_mon);
    PRINT_INT(g_calender -> tm_mday);
    PRINT_INT(g_calender -> tm_hour);
    PRINT_INT(g_calender -> tm_min);
    PRINT_INT(g_calender -> tm_sec);

    return 0;
}