//
// Created by helisi on 2022/7/23.
//
#include <stdio.h>

int global_var = 10;

double Add(double a, double b) {
    printf("global_var: %d\n", global_var);
    return a + b;
}

double Sort(int size, int array[size]);

void LocalStaticVar(void) {
    static int static_var;
    int non_static_var;
    printf("static_var: %d\n", static_var++);
    printf("non_static_var: %d\n", non_static_var++);
}

void PassByMemory(int paramter) {
    printf("%d\n", paramter);
}

// 寄存器变量
void PassByRegister(register int parameter) {
    printf("%d\n", parameter);
}

int main(void) {

    // 自动变量
    auto int value = 1;

    // 块作用域
    {
        auto int block_auto_a = 2;
        printf("block_auto_a: %d\n", block_auto_a);
        printf("auto_value: %d\n", value);
        printf("global_var: %d\n", global_var);
        global_var ++;
    }

    double addResult = Add(1.0, 2.0);
    printf("add result: %lf\n", addResult);
    global_var ++;
    printf("global_var: %d\n", global_var);

    LocalStaticVar();
    LocalStaticVar();
    LocalStaticVar();

    return 0;
}