//
// Created by helisi on 2022/8/5.
//
#include <stdio.h>
#include "include/Print_Utils.h"

int main(void) {

//    int a;
//    a = 2;
//
//    int *p = &a;
//    *p = 4;
//    PRINT_INT(a);
//
//    int b = *p;
//    PRINT_INT(b);

    int array[5] = {0};
    PRINT_INT_ARRAY(array, 5);
    int *p = array;
    for (int j = 0; j < 5; ++j) {
        *(p+j) = j;
    }
    PRINT_INT_ARRAY(array, 5);

    int a = *(p+4) + 4;
    PRINT_INT(a);

    return 0;
}