//
// Created by helisi on 2022/11/27.
//
#include <stdio.h>
#include <errno.h>
#include "include/io_utils.h"
#include "include/time_utils.h"

#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -100

#define BUFFERSIZE 512

// 最快的拷贝方式
int CopyFile(char const *src, char const *dest) {
    if(!src || !dest) {
        return COPY_ILLEGAL_ARGUMENTS;
    }
    char buffer[BUFFERSIZE];
    FILE *read = fopen(src, "rb");
    if(!read) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *write = fopen(dest, "wb");
    if(!write) {
        fclose(read);
        return COPY_DEST_OPEN_ERROR;
    }

    int result;

    while(1) {
        size_t readSize = fread(buffer, sizeof(buffer[0]), BUFFERSIZE, read);
        if(fwrite(buffer, sizeof(buffer[0]), readSize, write) < readSize) {
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
        if(readSize < BUFFERSIZE) {
            if(feof(read)) {
                result = COPY_SUCCESS;
            }else if(ferror(read)) {
                result = COPY_SRC_READ_ERROR;
            }else {
                result = COPY_UNKNOWN_ERROR;
            }
            break;
        }
    }
    fclose(read);
    fclose(write);
    return result;
}


int main() {

    return 0;
}
