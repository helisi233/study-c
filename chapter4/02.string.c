//
// Created by helisi on 2022/8/1.
//
#include <stdio.h>
#include "include/Print_Util.h"

int main(void) {

    char string1[11] = "Hello World";
    char string2[12] = "Hello World";
    char string3[] = "Hello World";

    for (int i = 0; i < 11; ++i) {
        Print_Char(string1[i]);
    }

    Printlnf("%s", string2);
    Printlnf("%s", string3);

    char string_zh[] = "你好，世界";
    Printlnf("%s", string_zh);

    wchar_t wc[] = L"你好，世界";

    return 0;
}