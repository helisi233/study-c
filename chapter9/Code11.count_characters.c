//
// Created by helisi on 2022/11/29.
//
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "include/io_utils.h"

#define ERROR_ILLEGAL_FILENAME -1
#define ERROR_CANNOT_OPEN_FILE -2
#define ERROR_READ_FILE -3
#define ERROR_UNSUPPORTED_CHATSET -99

#define CHARSET_UTF8 0
#define CHARSET_GBK 1

int CountCharactersInFile(char const *filename, int charset) {
    if(!filename) {
        return ERROR_ILLEGAL_FILENAME;
    }

    FILE *file;
    switch (charset) {
        case CHARSET_GBK:
#ifdef _WIN32
            setlocale(LC_ALL, "chs");
#else
            setlocale(LC_ALL, "zh_CN.gbk");
#endif
            file = fopen(filename, "r");
            break;
        case CHARSET_UTF8:
            setlocale(LC_ALL, "zh_CN.utf-8");
#ifdef _WIN32
            file = fopen(filename, "r, ccs=utf-8");
#else
            file = fopen(file, "r");
#endif
            break;
        default:
            return ERROR_UNSUPPORTED_CHATSET;
    }

    if(!file) {
        return ERROR_CANNOT_OPEN_FILE;
    }

#define BUFFER_SIZE 512
    wchar_t wcs[BUFFER_SIZE];
    int count = 0;
    // fgetws按宽字符从file流里面读取 如果读取发生异常返回NULL 否则返回wcs宽字符数组
    while(fgetws(wcs, BUFFER_SIZE, file)) {
        int c = wcslen(wcs);    // 返回宽字符数组长度
        count += c;
    }

    if(ferror(file)) {
        perror("CountCharactersInFile");
        return ERROR_READ_FILE;
    }

    fclose(file);

    return count;
}

// 统计文件字符数
int main() {

    return 0;
}