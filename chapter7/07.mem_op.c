//
// Created by helisi on 2022/11/15.
//
#include <stdlib.h>
#include <string.h>
#include "include/io_utils.h"

// 常见内存拷贝函数
int main() {

    char dest[] = "C said ";
    char *src = "Hello World";
    // 从src拷贝n个字节到dest dest必须是可变字符串
    // 声明可变字符串char[] 声明不可变字符串char*
    // 用在不存在内存覆盖的情况下
    memcpy(dest, src, strlen(src)+1);
    puts(dest);

    // memchr(src, c, maxsize)
    // 在src里面搜索c第一次出现的位置 最多搜索范围maxsize
    // 返回一个指针 指向c第一次出现的位置
    char *c = (char*)memchr("Hello World", 'e', 11);
    puts(c);

    char str1[] = "abcdef";
    char str2[] = "ABCDEF";
    // 比较str1和str2 最多比较6个字节
    // 返回0 str1=str2 返回>0 str1>str2 返回<0 str1<str2
    memcmp(str1, str2, 6);

    // memset(void *_Dst,int _Val,size_t _Size) 把dst整块内存赋值成val
    // 一般用在内存初始化后 清零
    char *mem = malloc(10);
    memset(mem, 0, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", *mem);
    }
    printf("\n");
    free(mem);

    // 内存覆盖的情况使用memmove
    char *src1 = "HelloWorld";
    char *dest1 = malloc(11);
    memset(dest1, 0, 11);
    memcpy(dest1, src1, 11);
    puts(dest1);
    memmove(dest1+3, dest1+1, 4);
    puts(dest1);
    free(dest1);

    return 0;
}