//
// Created by helisi on 2022/7/25.
//
#include "../include/factorial.h"

unsigned int Factorial(unsigned int n) {
    if(n == 0) {
        return 1;
    }
    return n * Factorial(n-1);
}

unsigned int FactorialByIter(unsigned int n) {
    int result = 1;
    for (int i = n; i > 0; --i) {
        result *= i;
    }
    return result;
}