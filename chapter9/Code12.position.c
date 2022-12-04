//
// Created by helisi on 2022/11/29.
//
#include <stdio.h>
#include <locale.h>
#include "include/io_utils.h"

// 输入输出流的位置
int main() {

    FILE *file = fopen("CMakeLists.txt", "rb");
    /*
     *  文件以字节流的形式读取
     *  ftell返回从开始到当前位置的字节数
     *
     *  字符形式打开 C标准没有定义 取决于编译器实现
     * */
    long position = ftell(file);
    PRINT_LONG(position);
    char buffer[50];
    // 从文件流读50个字节
    fread(buffer, sizeof(buffer[0]), 50, file);
    PRINT_LONG(ftell(file));

    /*
     *  从新定位流的位置
     *  fseek(stream, offset, position);
     *  offset偏移位置
     *  position
     *      SEEK_SET    文件开始
     *      SEEK_CUR    当前位置
     *      SEEK_END    文件末尾
     * */
    fseek(file, 10, SEEK_SET);  // 文件流开始往后10个字节
    PRINT_LONG(ftell(file));
    fseek(file, 10, SEEK_CUR);  // 文件流当前位置往后10个字节
    PRINT_LONG(ftell(file));
    fseek(file, -10, SEEK_END); // 文件流末尾往前10个字节
    PRINT_LONG(ftell(file));

    /*
     *  ftell、fseek只适用于窄字符
     *  宽字符涉及到编码3个字节->UTF8  2个字节->GBK
     *  stdout不能重定位
     * */

    fclose(file);

    return 0;
}