//
// Created by helisi on 2022/7/24.
//
#include <stdio.h>

// 使用递归的方式计算阶乘
unsigned int Factorial1(unsigned int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * Factorial1(n-1);
}

// 使用迭代的方式计算阶乘
unsigned int Factorial2(unsigned int n) {
    int result = 1;
    while(n != 1) {
        result *= n;
        n --;
    }
    return result;
}

// 递归计算斐波那契数列
unsigned int Fibonacci1(unsigned int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return Fibonacci1(n-1) + Fibonacci1(n-2);
}

// 迭代计算斐波那契数列
unsigned int Fibonacci2(unsigned int n) {
    int start = 0;
    int tmp = 1;
    int result = 0;
    for (int i = 0; i < n-2; ++i) {
        result = start + tmp;
        start = tmp;
        tmp = result;
    }
    return result;
}

// 打印斐波那契数列
void PrintFibonacci(unsigned int length) {
    if(length == 1) {
        printf("%d", 0);
        return;
    }
    if(length == 2) {
        printf("%d %d", 0, 1);
        return;
    }
    printf("%d %d ", 0, 1);
    int start = 0;
    int next = 1;
    int result = 0;
    for (int i = 0; i < length-2; ++i) {
        result = start + next;
        start = next;
        next = result;
        printf("%d ", result);
    }
}

int main(void) {

    printf("%d\n", Factorial1(3));
    printf("%d\n", Factorial2(3));

    printf("%d\n", Fibonacci1(3));
    printf("%d\n", Fibonacci2(6));

    PrintFibonacci(10);

    return 0;
}