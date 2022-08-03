//
// Created by helisi on 2022/8/3.
//
#include <stdio.h>
#include "include/Print_Util.h"

#define LENGTH 10

// 求定长
int SumIntArray(int array[LENGTH]) {
    int sum = 0;
    for (int i = 0; i < LENGTH; ++i) {
        sum += array[i];
    }
    return sum;
}

// 求不定长
int SumIntArray2(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum +=  array[i];
    }
    return sum;
}

int main(void) {
    int arr[LENGTH] = {1,2,3,4,5,6,7,8,9,10};
    int sum = SumIntArray(arr);
    Print_Int(sum);

    int arr2[] = {1,2,3,4,5};
    Print_Int(SumIntArray2(arr2, 5));

    int arr3[] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
    Print_Int(SumIntArray2(arr3, 15));
    return 0;
}