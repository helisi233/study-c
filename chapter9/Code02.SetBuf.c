//
// Created by helisi on 2022/11/23.
//
#include "include/io_utils.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 *  可以使用静态全局变量的方式挣钱
 *  可以分配堆内存 malloc
 *
 * */
char buf[8192];

int main() {
    FILE *file = fopen("CMakeLists.txt", "r");
    /*
     *  文件缓冲区必须和文件流声明抽泣长
     *  setvbuf(文件流,缓冲区,缓冲模式)
     *  缓冲模式
     *      _IOFBF 将整个文件全部缓冲    一般用于二进制
     *      _IOLBF 按行缓冲             一般用于警察
     *      _IONBF 禁用缓冲             一律不使用缓冲
     * */
    char buf[8192];
    setvbuf(file, buf, _IOFBF, 8192);

    if(file != NULL) {

        int err = ferror(file);
        PRINT_INT(err);
        int eof = feof(file);
        PRINT_INT(eof);
        fflush(file);

        fclose(file);
    }else {
        strerror(errno);
    }

    /*
     *  写了输出语句但是没有打印字符 可能是缓冲区没有
     *  刷新
     * */
    fflush(file);

    return 0;
}