//
// Created by helisi on 2022/8/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/Print_Utils.h"

#define ARRAY_LENGTH 20

int SwapInt(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int *GenerateArray(int length) {
    int *array = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        *(array+i) = i;
    }
    return array;
}

void PrintArray(int *array, int length) {
    if(array){
        for (int i = 0; i < length; ++i) {
            printf("%d, ", *(array+i));
        }
        printf("\n");
    }else {
        printf("array is null");
        return;
    }
}

void ShuffleArray(int **array, int length) {
    srand(time(NULL));
    for (int i = length-1; i > 0; --i) {
        int random_number = rand() % length;
        SwapInt(*array+i, *array+random_number);
    }
}

int Partition(int **array, int start, int end) {
    int pivot = *(*array+end);
    int partition = start;
    for (int i = start; i <= end; ++i) {
        if(*(*array+i) < pivot) {
            SwapInt(*array+i, *array+partition);
            partition++;
        }
    }
    SwapInt(*array+end, *array+partition);
    return partition;
}

void QuickSort(int **array, int start, int end) {
    if(start >= end) {
        return;
    }
    int partition = Partition(array, start, end);
    QuickSort(array, start, partition-1);
    QuickSort(array, partition+1, end);
}

int *Partition2(int *start, int *end) {
    int pivot = *(start + (end - start) / 2);
    int *p = start;
    int *q = end;
    while(1) {
        while(*p < pivot) p++;
        while(*q > pivot) q--;
        if(p >= q) break;
        SwapInt(p, q);
    }
    return q;
}

void QuickSort2(int *start, int *end) {
    if(start >= end) return;
    int *partition = Partition2(start, end);
    QuickSort2(start, partition-1);
    QuickSort2(partition+1, end);
}

int main(void) {
    int *array = GenerateArray(ARRAY_LENGTH);
    PrintArray(array, ARRAY_LENGTH);
    ShuffleArray(&array, ARRAY_LENGTH);
    PrintArray(array, ARRAY_LENGTH);

//    QuickSort(&array, 0, ARRAY_LENGTH-1);
    QuickSort2(array, array+ARRAY_LENGTH-1);
    PrintArray(array, ARRAY_LENGTH);
    free(array);

    return 0;
}
