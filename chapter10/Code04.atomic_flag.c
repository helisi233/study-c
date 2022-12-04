//
// Created by helisi on 2022/12/4.
//
#include <stdatomic.h>
#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

/*
 *  标志位 做线程取消
 * */
atomic_flag resume_flag = ATOMIC_FLAG_INIT;

int PrintNumbers(void *arg) {
    int current = 0;
    // 每一次检测后再设置回true
    while(atomic_flag_test_and_set(&resume_flag)) {
        current ++;
        PRINT_INT(current);
        thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
    }
    return current;
}

int main() {

    atomic_flag_test_and_set(&resume_flag);

    thrd_t t;
    thrd_create(&t, PrintNumbers, NULL);

    thrd_sleep(&(struct timespec){.tv_sec = 5}, NULL);

    // 清除标志位
    atomic_flag_clear(&resume_flag);

    int last_number;
    thrd_join(t, &last_number);
    PRINT_INT(last_number);

    return 0;
}