//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>

int main(void) {

    int value;
    int value_init;

    value = 4;
    value_init = 5;

    printf("value: %d\n", value);

    value_init = value;

    printf("value size: %d\n", sizeof(int));
    printf("value address: %x\n", &value);

    return 0;
}