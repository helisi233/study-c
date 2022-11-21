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
    PRINT
}

int main() {

    return 0;
}