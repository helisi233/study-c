//
// Created by helisi on 2022/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/Print_Util.h"

void SwapElement(int array[], int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

void ShuffleArray(int array[], int length) {
    srand(time(NULL));
    for (int i = length-1; i > 0; --i) {
        int random_number = rand() % length;
        SwapElement(array, i, random_number);
    }
}

/*
 *  快速排序
 *  i: 用来遍历数组
 *  position: 用来标记分割数组的位置
 *  流程:
 *      i进行遍历
 *      如果arr[i] < arr[length-1]
 *          i++
 *          position++
 *      如果arr[i] > arr[length-1]
 *          i++
 *      找到position位置 然后进行递归
 * */
int Partition(int array[], int start, int end) {
    int posititon = start;
    int pivot = array[end];
    for (int i = start; i <= end; ++i) {
        if(array[i] < pivot) {
            SwapElement(array, i, posititon);
            posititon ++;
        }
    }
    SwapElement(array, end, posititon);
    return posititon;
}

void QuickSort(int array[], int start, int end) {
    if(start >= end) return;
    int partition = Partition(array, start, end);
    QuickSort(array, start, partition-1);
    QuickSort(array, partition+1, end);
}

int main(void) {

    int players[20];
    for (int i = 0; i < 20; ++i) {
        players[i] = i;
    }
    ShuffleArray(players, 20);
    Print_Int_Array(players, 20);

    QuickSort(players, 0, 19);
    Print_Int_Array(players, 20);

    return 0;
}