//
// Created by helisi on 2022/11/13.
//
#include <stdlib.h>
#include <errno.h>
#include "include/io_utils.h"

// 字符串与其他类型的转换
/*
 * atoX 使用简单 适用于简单 要求不高的场景
 * strtoX 可重复解析 安全
 * */
int main(void) {
    PRINT_INT(atoi("1234"));
    PRINT_INT(atoi("-1234"));
    PRINT_INT(atoi("    1234abcd"));
    PRINT_INT(atoi("0x10"));    // atoi不支持十六进制 输出0

    PRINT_FLOAT(atof("12.34"));
    PRINT_FLOAT(atof("-12e34"));
    PRINT_FLOAT(atof("   1.234abcd"));
    PRINT_FLOAT(atof("0x10"));
    PRINT_FLOAT(atof("0x10p3.9"));


    char const *const kInput = "1 200000000000000000000000 3 -4 5abcd bye";
    PRINTLNF("Parse: %s", kInput);
    char const *start = kInput;
    char *end;
    while(1) {
        errno = 0;
        /*
         *  start 要解析的字符串
         *  &end   解析完字符串后移动到下次要解析的位置
         *  radix   解析出的进制
         * */
        // 一般函数需要传入指针的指针 表示在这个函数中这个指针是需要被修改的
        const long i = strtol(start, &end, 10);
        if(start == end) {
            break;
        }

        /*
         *  %s 打印字符串
         *  %.*s 多传入长度参数 打印固定长度的字符串
         * */
        printf("'%.*s'\t ==> %ld.", (int)(end - start), start, i);

        /*
         *  标准输出和标准错误使用不同的流
         *  打印位置和优先级是不同的
         * */
        if(errno == ERANGE) {
            perror("溢出 解析的字符串无法转成long类型");
        }

        putchar('\n');
        start = end;
    }
    PRINTLNF("Parse End");

    return 0;
}