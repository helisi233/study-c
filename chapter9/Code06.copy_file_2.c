//
// Created by helisi on 2022/11/26.
//
#include <stdio.h>
#include "include/io_utils.h"
#include "include/time_utils.h"

#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -100

int CopyFile(char const *src, char const *dest) {
    if(!src || !dest) {
        return COPY_ILLEGAL_ARGUMENTS;
    }
    FILE *open = fopen(src, "r");
    if(!open) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *write = fopen(dest, "w");
    if(!write) {
        fclose(open);
        return COPY_DEST_OPEN_ERROR;
    }
    int result = COPY_SUCCESS;
    char buffer[1024];
    char *next;
    while(1) {
        next = fgets(buffer, 1024, open);
        if(!next) {
            if(ferror(open)) {
                result = COPY_SRC_READ_ERROR;
            }else if(feof(open)) {
                result = COPY_SUCCESS;
            }else {
                result = COPY_UNKNOWN_ERROR;
            }
            break;
        }
        if(fputs(buffer, write) == EOF) {
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