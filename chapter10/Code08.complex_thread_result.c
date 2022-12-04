//
// Created by helisi on 2022/12/4.
//
#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

typedef struct {
    int a;
    char *b;
} ComplexResult;

typedef struct {
    int arg;
    ComplexResult result;
} ComplexArg;

int ComplexReturnValue(ComplexArg *arg) {
    ComplexResult *complex_result = &(arg -> result);
    /*
     *  处理复杂线程结果
     *  将需要修改的结构体封装到另一个结构体中 作为参数传入
     *  再封装结构体中声明后 结构体占用的内存已经被分配
     *
     *  函数的返回值表示是否修改成功
     * */
    complex_result -> a = 2;
    complex_result -> b = "Hello World";
    return 0;
}

int main() {

    ComplexArg complex_arg = {.arg = 1};
    thrd_t t;
    thrd_create(&t, ComplexReturnValue, &complex_arg);

    int result;
    thrd_join(t, &result);

    ComplexResult *complex_result = &(complex_arg.result);
    PRINT_INT(complex_result -> a);
    puts(complex_result -> b);

    return 0;
}