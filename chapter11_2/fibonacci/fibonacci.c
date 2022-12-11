//
// Created by helisi on 2022/12/8.
//
#include "fibonacci.h"

unsigned int Fibonacci(unsigned int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
}