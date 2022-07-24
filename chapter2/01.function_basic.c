//
// Created by helisi on 2022/7/23.
//
#include <stdio.h>

double f(double x) {
    return x * x + x + 1;
}

double g(double x, double y, double z) {
    return x * x + y * y + z * z;
}

int main(void) {

    puts("Hello World");

    double result_f = f(2.0);
    double result_g = g(3.0, 4.0, 5.0);

    printf("result_f: %lf\n", result_f);
    printf("result_g: %lf\n", result_g);

    return 0;
}