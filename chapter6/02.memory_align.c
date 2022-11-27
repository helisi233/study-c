//
// Created by helisi on 2022/8/8.
//
#include <stdio.h>
#include "include/Print_Utils.h"

#pragma pack(2)

int main(void) {

    typedef struct Person {
        char *name;
        int age;
        char *id;
    }Person;

    Person person = {.name = "hls", .id="11223344"};
    PRINT_STR(person.name);

    /**
     *  优化前内存占用 24字节
     *  mingw64位环境 char* -> 8字节 int -> 4字节
     *  因为需要内存对齐 由于占用4字节的变量放在两个占用8字节的变量中间 为了访问效率需要内存对齐
     *  所以中间会有4个空白字节用于占位 8字节 + {4字节 + 4个空白字节} + 8字节
     *  相当于浪费了4个字节
     * */
    PRINT_INT(sizeof(Person));

    // 原始状态 占用24字节
    typedef struct {
        char a;     // 1字节
        char b;     // 1字节
        __attribute((aligned(2))) int c;      // 4字节
        short d;    // 2字节
        double e;   // 8字节
    }Align;
    Align align = {'a', 'b', 3, 4, 5.0};
    PRINT_INT(sizeof(Align));
    PRINT_INT(_Alignof(align.c));

    // 调整变量顺序 只占用16字节
    typedef struct {
        char a;     // 1字节
        char b;     // 1字节
        short d;    // 2字节
        int c;      // 4字节
        double e;   // 8字节
    }Align2;
    PRINT_INT(sizeof(Align2));

    PRINT_INT((size_t)&(((Align2*)0) -> c));

    return 0;
}