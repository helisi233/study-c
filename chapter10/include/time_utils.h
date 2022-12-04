//
// Created by helisi on 2022/11/26.
//

#ifndef STUDY_C_TIME_UTILS_H
#define STUDY_C_TIME_UTILS_H

#include <time.h>
#include "../tinycthread/include/tinycthread.h"

typedef long long long_time_t;

long_time_t TimeInMillisecond(void) {
    struct timeb time_buffer;
    ftime(&time_buffer);
    return time_buffer.time * 1000LL + time_buffer.millitm;
}

void TimeCost(char const *msg) {
    static long_time_t start_time = 0;
    if(msg && start_time != 0) {
        long_time_t current_time = TimeInMillisecond();
        PRINTLNF("%s costs: %lld", msg, current_time - start_time);
    }
    start_time = TimeInMillisecond();
}

void SleepMs(long milliseconds) {
    long seconds = milliseconds / 1000;
    long nanoseconds = (milliseconds % 1000) * 1000000L;
    thrd_sleep(&(
    struct timespec){.tv_sec = seconds, .tv_nsec = nanoseconds}, NULL);
}

#endif //STUDY_C_TIME_UTILS_H
