//
// Created by helisi on 2022/12/4.
//
#include <stdatomic.h>
#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

atomic_int count = 0;

int Counter(void *arg) {
    PRINTLNF("Counter.");
    for (int i = 0; i < 1000000; ++i) {
        count ++;
    }
    return 0;
}

int main() {

    thrd_t t_1, t_2;
    thrd_create(&t_1, Counter, NULL);
    thrd_create(&t_2, Counter, NULL);

    thrd_join(t_1, NULL);
    thrd_join(t_2, NULL);

    PRINT_INT(count);

    return 0;
}