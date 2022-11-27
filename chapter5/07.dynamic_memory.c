//
// Created by helisi on 2022/8/6.
//
#include <stdio.h>
#include <stdlib.h>
#include "include/Print_Utils.h"

#define PLAYER_COUNT 10

void InitPointer(int **ptr, int length, int default_value) {
    *ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
//        下面这两句都一样 []的优先级比*大
        *(*ptr+i) = default_value;
//        (*ptr)[i] = default_value;
    }
}

int main(void) {

    int *array = malloc(sizeof(int) * PLAYER_COUNT);
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        *(array+i) = i;
    }
    PRINT_INT_ARRAY(array, PLAYER_COUNT);
    free(array);

    int *array2;
    InitPointer(&array2, PLAYER_COUNT, 34);
    PRINT_INT_ARRAY(array2, PLAYER_COUNT);
    free(array2);

    int *array3;
    array3 = calloc(PLAYER_COUNT, sizeof(int));
    PRINT_INT_ARRAY(array3, PLAYER_COUNT);

    array3 = realloc(array3, PLAYER_COUNT * sizeof(int) * 2);
    PRINT_INT_ARRAY(array3, PLAYER_COUNT * 2);

    if(array3) {
        free(array3);
        printf("销毁array3的内存空间\n");
    }else {

    }




    return 0;
}