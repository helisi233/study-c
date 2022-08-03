//
// Created by helisi on 2022/8/3.
//
#include <stdio.h>
#include "include/Print_Util.h"

void SumInt2DArray(int row, int column, int array[][column], int result[]) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result[i] += array[i][j];
        }
    }
}

int SumIntArray(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}

int main(void) {

    // 一个5行2列的二维数组
    int vehicle_limits[5][2];
    // int [2]
    vehicle_limits[0];

    int array[] = {1,2,3,4,5};
    Print_Int(SumIntArray(array, 5));

    int scores[5][4] = {
            {135, 135, 138, 277},
            {105, 134, 108, 265},
            {113, 107, 145, 232},
            {123, 99, 140, 227},
            {98, 118, 127, 242}
    };
    int result[5] = {0};
    SumInt2DArray(5, 4, scores, result);
    Print_Int_Array(result, 5);

    return 0;
}