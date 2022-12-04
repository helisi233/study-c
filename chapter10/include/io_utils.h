//
// Created by helisi on 2022/11/23.
//

#ifndef STUDY_C_IO_UTILS_H
#define STUDY_C_IO_UTILS_H

#include <stdio.h>

#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)
#define PRINT_INT(value) PRINTLNF(#value": %d", value)
#define PRINT_LONG(value) PRINTLNF(#value": %ld", value)
#define PRINT_LLONG(value) PRINTLNF(#value": %lld", value)

#endif //STUDY_C_IO_UTILS_H
