//
// Created by helisi on 2022/11/15.
//
#include <stdlib.h>
#include <string.h>
#include "include/io_utils.h"

int main() {

#ifdef __STDC_LIB_EXT1__
    puts("support C11 safe version.");
#else
    puts("No support for C11 safe version");
#endif

    char dst[2];
    // 最多往dst里面拷贝2个字节
    int error_no = strcpy_s(dst, 2, "Too long");
    PRINT_INT(error_no);
    if(error_no) {
        perror("strcpy_s return: ");
    }

    return 0;
}