//
// Created by helisi on 2022/8/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "include/Print_Utils.h"

#define ARRAY_LENGTH 10

// ()的优先级比*高 相当于int *(f(int, double)) 这是一个函数f(int, double)返回int*
int *f1(int, double);
// f2是一个函数指针 接收int和double 返回int
int (*f2)(int, double);
// f3是一个函数指针 接收int和double 返回int*
int *(*f3)(int, double);
// f4是一个函数指针 接收int和double 返回int[] 但是C语言不支持返回数组 这是一个非法声明
// int (*f4)(int, double)[];
// f5是一个数组 一个函数指针的数组
int (*f5[])(int, double);
// f6是一个函数指针 接收int和double 返回函数的数组 但是C语言不支持返回函数数组 这是一个非法声明
// int (*f6)[](int, double);

// 定义 Func是一个指向int (int,double)这种类型函数的指针
typedef int (*Func)(int, double);
int Add(int a, double b) {
    return a + (int)b;
}

// 函数原型
int SumIntArray(int array[], int length);

void InitPointer(int **ptr, int length, int default_value) {
    *ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
//        *(*ptr+i) = default_value;
        (*ptr)[i] = default_value;
    }
}

// 给int*起一个别名IntPtr
typedef int* IntPtr;
// 给int[]起一个别名IntArray
typedef int IntArray[];

int main(void) {

    // main函数的起始地址
    PRINT_INT_HEX(&main);
    // InitPointer函数的起始地址
    PRINT_INT_HEX(&InitPointer);

    IntPtr array;
//  void (int **ptr, int length, int default_value) (*func2) = &InitPointer;
//  可以理解为上面的写法 只是需要将(*func2)放在函数参数的前面
    void (*func2)(int **ptr, int length, int default_value) = &InitPointer;

    IntArray array2 = {1,2,3,4,5};
    PRINT_INT_ARRAY(array2, 5);

    func2(&array, ARRAY_LENGTH, 34);

    (*func2)(&array, ARRAY_LENGTH, 45);
    (*InitPointer)(&array, ARRAY_LENGTH, 56);
    PRINT_INT_ARRAY(array, ARRAY_LENGTH);

    free(array);

    Func func3 = &Add;
    int result = func3(1, 3.0);
    PRINT_INT(result);
    func3 = NULL;

    return 0;
}