//
// Created by helisi on 2022/7/25.
//
#include <stdio.h>

//#define DEBUG

void dump(char *message) {
#ifdef DEBUG
    puts(message);
#endif
}

int main(void) {
    dump("main start");
    puts("Hello World");
    printf("__STDC_VERSION__: %d\n", __STDC_VERSION__);
#ifdef __STDC_VERSION__ >= 201112
    puts("C11");
#elif __STDC_VERSION__ >= 199901
    puts("C99");
#else
    puts("maybe C90");
#endif
    dump("main end");
    return 0;
}