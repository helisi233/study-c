//
// Created by helisi on 2022/8/9.
//
#include <stdio.h>
#include "include/Print_Utils.h"

/**
 *  判断字节序
 * */
int IsBigEndian() {
    union {
        char c[2];
        short s;
    }value = {.s = 0x100};
    return value.c[0] == 1;
}

int IsBigEndian2() {
    short s = 0x100;
    char *p = (char*)&s;
    return *p == 1;
}

/**
 *  交换字节序
 * */
int ToggleEndian(int original) {
    union {
        char c[4];
        int i;
    }value = {.i = original};
    char temp = value.c[0];
    value.c[0] = value.c[3];
    value.c[3] = temp;
    temp = value.c[1];
    value.c[1] = value.c[2];
    value.c[2] = temp;
    return value.i;
}

int ToggleEndian2(int original) {
    char *p = (char*)&original;
    char temp = *p;
    *p = *(p+3);
    *(p+3) = temp;
    temp = *(p+1);
    *(p+1) = *(p+2);
    *(p+2) = temp;
    return original;
}

int main(void) {

    PRINT_INT(IsBigEndian());
    PRINT_INT(IsBigEndian2());

    int original = 0x12345678;
    PRINT_INT_HEX(original);
    PRINT_INT_HEX(ToggleEndian2(original));

    return 0;
}