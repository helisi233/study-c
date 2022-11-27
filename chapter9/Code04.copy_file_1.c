//
// Created by helisi on 2022/11/26.
//
#include <stdio.h>

/*
 * 定义返回值
 * 0 成功
 * -1 参数错误
 * -2 打开读文件错误
 * -3 读文件错误
 * -4 打开写文件错误
 * -5 写文件错误
 * -100 未知错误
 * */
#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -100

int CopyFile(char const *src, char const *dest) {
    if(src == NULL || dest == NULL) {
        return COPY_ILLEGAL_ARGUMENTS;
    }

    FILE *open = fopen(src, "r");
    if(open == NULL) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *write = fopen(dest, "w");
    if(write == NULL) {
        fclose(open);
        return COPY_DEST_OPEN_ERROR;
    }
    int result;
    while(1) {
        int next = getc(open);
        if(next == EOF) {
            if(ferror(open)) {
                result = COPY_SRC_READ_ERROR;
            }else if(feof(open)) {
                result = COPY_SUCCESS;
            }else {
                result = COPY_UNKNOWN_ERROR;
            }
            break;
        }
        if(putc(next, write) == EOF) {
            /*
             *  写入文件不需要考虑写完
             *  但是可能出现磁盘空间不足或者写入失败
             * */
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
    }
    fclose(open);
    fclose(write);
    return result;
}

int main() {

    return 0;
}