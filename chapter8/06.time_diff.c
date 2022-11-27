//
// Created by helisi on 2022/11/22.
//
#include "include/io_utils.h"
#include "include/time_utils.h"

#define PI 3.1415926

void DoHardWork() {
    double sum = 0;
    for (int i = 0; i < 10000000; ++i) {
        sum += i * i/PI;
    }
    PRINT_DOUBLE(sum);
}

int main() {

    time_t start_time = time(NULL);
    DoHardWork();
    time_t end_time = time(NULL);
    // 计算时间差difftime(time_t,time_t)
    double diff = difftime(start_time, end_time);
    PRINT_DOUBLE(diff);

    // clock() 获取处理器时间
    clock_t start_time_c = clock();
    DoHardWork();
    clock_t end_time_c = clock();
    PRINT_DOUBLE((end_time_c - start_time_c) * 1.0 / CLOCKS_PER_SEC);

    return 0;
}