//
// Created by helisi on 2022/8/6.
//
#include <stdio.h>
#include "include/Print_Utils.h"

int SumIntArray(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    // mov  eax,DWORD PTR[rbp-4]
    return sum;
}

void SumIntArrayPointer(int array[], int length, int *sum) {
    *sum = 0;
    for (int i = 0; i < length; ++i) {
        *sum += array[i];
    }
}

int main(void) {
    int array[] = {1,2,3,4,5};
    // mov DWORD PTR[rbp-4],eax
    int sum = SumIntArray(array, 5);

    int sum2 = 0;
    SumIntArrayPointer(array, 5, &sum2);
    PRINT_INT(sum2);

    return 0;
}