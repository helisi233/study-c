//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>

int main(void) {

    // 字符集
    char a = 'a';
    char char_1 = '1';

    char i = 0;

    char char_1_escape_oct = '\61';
    char char_1_escape_hex = '\x31';
    char newline = '\n';

    printf("char a: %d\n", a);
    printf("char 1: %d\n", char_1);
    printf("char 'i': %d\n", i);

    printf("char 1: %c\n", char_1);
    printf("char_1_escape_oct: %c\n", char_1_escape_oct);
    printf("char_1_escape_hex: %c\n", char_1_escape_hex);

    wchar_t zhong = L'中';
    printf("中: %d\n", zhong);
    wchar_t zhong_hex = L'\u4E2D';
    printf("中: %d\n", zhong_hex);

    return 0;
}