//
// Created by helisi on 2022/12/4.
//
#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

int count = 0;
mtx_t mutex;

int Counter(void *arg) {

    PRINTLNF("Counter.");
    for (int i = 0; i < 1000000; ++i) {
        mtx_lock(&mutex);
        count ++;
        mtx_unlock(&mutex);
    }

    return 0;
}

int main() {

    mtx_init(&mutex, mtx_plain);

    thrd_t t_1, t_2;
    thrd_create(&t_1, Counter, NULL);
    thrd_create(&t_2, Counter, NULL);

    thrd_join(t_1, NULL);
    thrd_join(t_2, NULL);

    PRINT_INT(count);

    mtx_destroy(&mutex);

    return 0;
}