//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>
#include <limits.h>

int main(void) {

    short si = 0;
    int i = 0;
    long li = 0;
    long long lli = 0;

    unsigned int ui = 123;

    printf("short int: %d\n", sizeof(short int));
    printf("int: %d\n", sizeof(int));
    printf("long int: %d\n", sizeof(long int));
    printf("long long int: %d\n", sizeof(long long int));

    printf("max int: %d, min int: %d\n", INT_MAX, INT_MIN);
    printf("unsigned max int: %u, unsigned min int: %d\n", UINT_MAX, 0);

    return 0;
}