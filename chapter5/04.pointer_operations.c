//
// Created by helisi on 2022/8/5.
//
#include <stdio.h>
#include "include/Print_Utils.h"

int main(void) {

    int array[] = {1,2,3,4,5};
    int *p = array;
    PRINT_INT(*(p+3));
    PRINT_INT(p[3]);
    PRINT_INT(*(array+3));
    PRINT_INT(array[3]);

    PRINT_INT(p+3 > p+1);

    return 0;
}