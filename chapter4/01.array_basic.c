//
// Created by helisi on 2022/8/1.
//
#include <stdio.h>
#include "include/Print_Util.h"

#define ARRAY_SIZE 10

int main(void) {

    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i * 10 + 1;
    }

    Print_Int_Array(array, ARRAY_SIZE);
    Print_Array_Ln("%d, ", array, ARRAY_SIZE);

    return 0;
}