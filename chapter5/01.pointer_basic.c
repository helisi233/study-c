//
// Created by helisi on 2022/8/4.
//
#include <stdio.h>
#include "include/Print_Utils.h"

int main(void) {

    int a = 100;
    int *p = &a;
    PRINT_INT_HEX(p);
    PRINT_INT_HEX(&a);

    PRINT_INT(a);
    PRINT_INT(*p);

    return 0;
}