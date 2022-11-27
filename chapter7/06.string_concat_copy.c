//
// Created by helisi on 2022/11/15.
//
#include <stdlib.h>
#include <string.h>
#include "include/io_utils.h"

int main() {

    char src[] = "Hello World";
    char dest[20] = "C said ";

    // 字符串连接 src放在dest后面
//    strcat(dest, src);
    puts(dest);

    // 字符串拷贝 默认覆盖 拷贝到目标位置后面
    strcpy(dest + strlen(dest), src);
    puts(dest);

    return 0;
}