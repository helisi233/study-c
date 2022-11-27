//
// Created by helisi on 2022/8/9.
//
#include <stdio.h>
#include "include/Print_Utils.h"

typedef enum FileFormat {
    PNG, JPEG, BMP, UNKNOWN
} FileFormat;

FileFormat GuessFormat(char *file_path) {
    FILE *file = fopen(file_path, "rb");
    FileFormat file_format = UNKNOWN;
    if(file) {
        char buffer[8] = {0};
        size_t bytes_count = fread(buffer, 1, 8, file);
        if(bytes_count == 8) {
            if(*((short*)buffer) == 0x4d42) {
                file_format = BMP;
            }else if(*((long long*)buffer) == 0x0a1a0a0d474e5089) {
                file_format = PNG;
            }else if(*((int*)buffer) == 0xe0ffd8ff) {
                file_format = JPEG;
            }
        }
        fclose(file);
    }
    return file_format;
}

int main(void) {
    PRINT_INT(GuessFormat("D:\\study-c\\chapter6\\images\\c.bmp"));
    // JPEG
    FileFormat fileFormat = 1;
    return 0;
}