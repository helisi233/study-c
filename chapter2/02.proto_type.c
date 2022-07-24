//
// Created by helisi on 2022/7/23.
//
//#include <stdio.h>

int __cdecl puts(const char *_Str);

void EmptyParamList() {
    puts("Hello World");
}

int Add(int, int);

int main(void) {

    EmptyParamList();
    EmptyParamList(1);
    EmptyParamList(1.0, "Hello");

//    int result = Add(1, 2);
//    printf("result: %d\n", result);

    puts("puts: Hello World");

    return 0;
}