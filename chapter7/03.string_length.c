//
// Created by helisi on 2022/11/13.
//
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "include/io_utils.h"

/*
 *  *指针 作为左值表示地址 作为右值表示指针指向的值
 * */
void SwapString(char **first, char **second) {
    char temp = *first;
    *first = *second;
    *second = temp;
}

void Shuffle(char** array, int length) {
    srand(time(NULL));
    for (int i = length-1; i > 0; --i) {
        int randomNumber = rand() % i;
        SwapString(array + i, array + randomNumber);
    }
}

char** Partition(char** low,char** high) {
    char* pivot = *(low+(high-low)/2);
    char** p = low;
    char** q = high;
    while(1) {
        while(strcmp(*p, pivot) < 0) p++;
        while(strcmp(*q, pivot) > 0) q--;
        if(p >= q) break;
        SwapString(p, q);
    }
    return q;
}

void QuickSort(char* *low, char* *high) {
    if(low >= high) return;
    char* *partition = Partition(low, high);
    QuickSort(low, partition-1);
    QuickSort(partition+1, high);
}

// 字符串的长度和比较
int main() {

    char *a = "abcd";
    for(int i = 0;i < 4;i ++) {
        printf("%c ", *(a+i));
    }


//    char *string = "Hello World";

//    PRINT_INT(strlen(string));
    // strlen_s安全版本的strlen 多了最大读取参数
//    PRINT_INT(strnlen_s(string, 100));

    /*
 *  字符串比较
 *  strcmp(const char *lhs, const char *rhs);
 *  strncmp(const char *lhs, const char *rhs, );
 * */
//    char *left = "Hello World";
//    char *right = "Hello C Programmers";
//
//    PRINT_INT(strcmp(left, right));
//    PRINT_INT(strncmp(left, right, 5));

    // 对字符串数组排序
    char *names[] = {
            "Cindy",
            "Don",
            "Andrey",
            "Elsa",
            "George",
            "Frank",
            "Benny"
    };

//    QuickSort(names, names+6);
//    PRINT_STRING(names, 7);


    return 0;
}