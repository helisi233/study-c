//
// Created by helisi on 2022/8/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/Print_Utils.h"

void SwapInt(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void Swap(void *first, void *second, size_t size) {
    void *temp = malloc(size);
    if(temp) {
        memcpy(temp, first, size);
        memcpy(first, second, size);
        memcpy(second, temp, size);
        free(temp);
    }else {

    }
}

// typeof(field) 在编译期获取field的类型
#define SWAP(a, b) do{ typeof(a) temp = a; a = b; b = temp; } while(0)

int main(void) {

    int a = 0;
    int b = 1;
    SwapInt(&a, &b);
    PRINT_INT(a);
    PRINT_INT(b);

    double c = 2.0;
    double d = 3.0;
    Swap(&c, &d, sizeof(double));
    PRINT_DOUBLE(c);
    PRINT_DOUBLE(d);

    float e = 4.f;
    float f = 5.f;
    SWAP(e, f);
    PRINT_FLOAT(e);
    PRINT_FLOAT(f);

    long g = LONG_MAX-1;
    long h = LONG_MAX;
    g = g ^ h;
    h = g ^ h;
    g = g ^ h;
    PRINT_LONG(g);
    PRINT_LONG(h);

    return 0;
}