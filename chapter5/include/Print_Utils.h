//
// Created by helisi on 2022/8/4.
//

#ifndef STUDY_C_PRINT_UTILS_H
#define STUDY_C_PRINT_UTILS_H

#ifdef DEBUG
#define PRINTLNF(format, ...) printf("("__FILE__":%d) %s: "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)
#endif

#define PRINT_INT(value) PRINTLNF(#value": %d", value)
#define PRINT_INT_HEX(value) PRINTLNF(#value": %x", value)
#define PRINT_LONG(value) PRINTLNF(#value": %ld", value)
#define PRINT_FLOAT(value) PRINTLNF(#value": %f", value)
#define PRINT_DOUBLE(value) PRINTLNF(#value": %lf", value)
#define PRINT_CHAR(value) PRINTLNF(#value": %c", value)
#define PRINT_STR(value) PRINTLNF(#value": %s", value)

#define PRINT_ARRAY(format, array, length) \
{ \
for(int i = 0;i < length; ++i) \
{ \
printf(format", ", array[i]); \
}; \
printf("\n"); }

#define PRINT_INT_ARRAY(array, length) PRINT_ARRAY("%d", array, length)

#endif //STUDY_C_PRINT_UTILS_H
