//
// Created by helisi on 2022/11/27.
//
#include <stdio.h>
#include "include/io_utils.h"

void Echo() {
#define BUFFERSIZE 32
    char buffer[BUFFERSIZE];
    while(1) {
        size_t readSize = fread(buffer, sizeof(buffer[0]), BUFFERSIZE, stdin);
        if(readSize < BUFFERSIZE) {
            if(feof(stdin)) {   // 读完了
                fwrite(buffer, sizeof(char), readSize, stdout);
                puts("EOF");
            }else if(ferror(stdin)) {   // 读取异常
                perror("");
            }
            break;
        }
        fwrite(buffer, sizeof(buffer[0]), BUFFERSIZE, stdout);
    }
}

int main() {
    Echo();
    return 0;
}