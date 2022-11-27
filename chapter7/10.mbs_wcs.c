//
// Created by helisi on 2022/11/15.
//
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "include/io_utils.h"

// 宽窄字符串的转换
int main() {

    // 窄字符版本isalpha    宽字符版本iswalpha
    PRINT_BOOL(iswalpha(L'A'));
    PRINT_BOOL(iswdigit(L'2'));

    wchar_t *wcs = L"你好 Hello";
    size_t  length = wcslen(wcs);
    PRINT_INT(length);

    wchar_t src[] = L"HelloWorld";
    wchar_t *dest = malloc(sizeof(wchar_t) * 11);
    wmemset(dest, 0, 11);
    wmemcpy(dest, src, 11);
    wprintf(dest);
    wmemmove(dest+3, dest+1, 4);
    wprintf(dest);
    free(dest);
    printf("\n");

    char *new_locale = setlocale(LC_ALL, "zh_CN.utf8");
    if(new_locale != NULL) {
        puts(new_locale);
    }

    {
        char mbs[] = "你好";
        wchar_t wcs[10];
        // mbstowcs(宽字符串 目标,窄字符串 源,目标最大容纳宽字符数)
        mbstowcs(wcs, mbs, 10);
        _putws(wcs);
    }


    return 0;
}

















