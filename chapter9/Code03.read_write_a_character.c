//
// Created by helisi on 2022/11/26.
//
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "include/io_utils.h"

void ReadFile() {
    FILE *file = fopen("CMakeLists.txt", "r");
    if(file != NULL) {
        int ch = getc(file);
        while(ch != EOF) {
            putchar(ch);
            ch = getc(file);
        }
        fflush(stdout);
        fclose(file);
    }else {
        perror(errno);
    }
}

int main() {

    // 回显用户输入
//    while(1) {
//        int next_input = getchar();
//        if(next_input == EOF) {
//            break;
//        }else if(next_input == '\n') {
//            continue;
//        }
//        putchar(next_input);
//    }

    ReadFile();

    return 0;
}