//
// Created by helisi on 2022/12/4.
//
#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"



int flag = 0;
volatile int a = 0;
int x = 0;

int T1(void *arg) {
    x = 2;
    flag = 1;
    x += 3;
    return 0;
}

int T2(void *arg) {
    while(!flag) {}
    x = a * a;
    return 0;
}

int main() {

    thrd_t t_1, t_2;

    thrd_create(&t_1, T1, NULL);
    thrd_create(&t_2, T2, NULL);

    thrd_join(t_1, NULL);
    thrd_join(t_2, NULL);

    PRINT_INT(x);

    return 0;
}