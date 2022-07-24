//
// Created by helisi on 2022/7/25.
//
#include <stdio.h>
#include <stdarg.h>

void PrintArgs(int arg_count, ...) {
    va_list args;
    va_start(args, arg_count);
    for (int i = 0; i < arg_count; ++i) {
        int arg = va_arg(args, int);
        printf("%d: %d\n", i, arg);
    }
    va_end(args);
}

void Printlnf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

#define DEBUG

#ifndef DEBUG
#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)
#else
#define PRINTLNF(format, ...) printf("("__FILE__":%d) %s: "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#endif
#define PRINT_INT(value) PRINTLNF(#value": %d\n", value)

int main(void) {
    PrintArgs(5, 10, 11, 12, 13, 14);
    Printlnf("int:%d float:%f double:%lf char:%c string:%s", 1, 1.f, 1.0, 'a', "Hello World");

    PRINTLNF("__STDC_VERSION__: %d", 11);
    int auto_value = 3;
    PRINT_INT(auto_value);
    return 0;
}