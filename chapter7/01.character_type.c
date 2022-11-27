//
// Created by helisi on 2022/11/13.
//
#include "include/io_utils.h"
#include <stdio.h>
#include <ctype.h>

// 判断0-9 数字类型是一个固定范围可以使用比较的方式 对于符号使用查表的方式最快
int IsDigit(char c) {
    return c >= '0' && c <= '9';
}

int main(void)
{

    // 这些函数在ctype.h中实现 标准库中使用查表的方式实现
    PRINT_INT(isdigit('0'));
    PRINT_INT(isspace(' '));
    PRINT_INT(isalpha('a'));
    PRINT_INT(isalnum('f'));
    PRINT_INT(isalnum('1'));
    PRINT_INT(ispunct(','));

    return 0;
}