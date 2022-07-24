//
// Created by helisi on 2022/7/23.
//
#include <stdio.h>
#include <stdarg.h>

void HandleVarargs(int arg_count, ...) {
    // 获取变长参数
    va_list args;
    // 开始遍历
    va_start(args, arg_count);
    for (int i = 0; i < arg_count; ++i) {
        // 取出对应参数 va_arg(va_list, type)
        int arg = va_arg(args, int);
        printf("%d: %d\n", i, arg);
    }
    // 结束遍历
    va_end(args);
}

int main(void) {
    printf("Hello World\n");
    HandleVarargs(5, 10, 11, 12, 13, 14);
    return 0;
}