//
// Created by helisi on 2022/11/13.
//

#include <stdio.h>
#ifndef STUDY_C_IO_UTILS_H
#define STUDY_C_IO_UTILS_H


#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)

#define PRINT_INT(value) PRINTLNF(#value": %d", value)

#define PRINT_LONG(value) PRINTLNF(#value": %ld", value)
#define PRINT_LLONG(value) PRINTLNF(#value": %lld", value)

#define PRINT_BOOL(value) PRINTLNF(#value": %d", value)

#define PRINT_FLOAT(value) PRINTLNF(#value": %f", value)
#define PRINT_DOUBLE(value) PRINTLNF(#value": %lf", value)

#define PRINT_CHAR(value) PRINTLNF(#value": %c", value)

#define PRINT_ARRAY(format, array, length) { \
    for(int i = 0; i < length;i ++) { \
        printf(format" ", array[i]); \
    }; \
printf("\n");}

#define PRINT_STRING(array, length) { \
    PRINT_ARRAY("%s", array, length); \
}

#endif //STUDY_C_IO_UTILS_H
