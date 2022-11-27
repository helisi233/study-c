//
// Created by helisi on 2022/11/13.
//
#include <string.h>
#include "include/io_utils.h"

int main() {

    /*
     *  C语言中没有字符串类型string 使用char*代替
     *  char *name; 等价于其他语言  String name;
     *  char* names[] 等价于其他语言 String names[]
     * */
    char *name = "Cindy";   // name这个指针指向了C这个字母
    for (int i = 0; i < 5; ++i) {
        // name+0 => C这个字母的地址 *(name+0)->'C'
        // name+1 => i这个字母的地址 *(name+1)->'i' 以此类推
        printf("%c", *(name+i));
    }
    printf("\n");
    /*
     *  name1这个指针指向char类型
     *  可以声明一个names指向char*类型
     * */
    char *n1 = "Cindy"; // n1指向'C'这个字母 *n1->'C'
    PRINT_INT(strlen(n1));
    char *n2 = "Bob";   // n2指向'B'这个字母 *n2->'B'
    PRINT_INT(strlen(n2));
    char* *names = {n1, n2};    // names指向n1这个指针 *names->n1

    int a = 3;
    int *ap = &a;
    int* *app = &ap;
//    PRINT_INT(a);
//    PRINT_INT(*ap);
//    PRINT_INT(**app);
    printf("%x\n", &ap);
    printf("%x\n", app);

    // 查找字符串
    char *string = "Hello World";
    char *result = strchr(string, 'l');
    char *result_reverse = strrchr(string, 'l');
    puts(result);
    puts(result_reverse);

    // strpbrk根据多个字符进行查找
    char *string2 = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
    char *break_set = ",;";
    int count = 0;
    char *p = string2;
    do{
        p = strpbrk(p, break_set);
        if(p != NULL) {
            puts(p);
            p ++;
            count ++;
        }
    }while(p != NULL);

    // 子串
    char *substring_position = strstr(string, "Wor");
    puts(substring_position);
    PRINT_INT(substring_position - string);

    return 0;
}