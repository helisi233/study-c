//
// Created by helisi on 2022/8/8.
//
#include <stdio.h>
#include "include/Print_Utils.h"

int main(void) {

    /**
     *  定义结构体时同时创建结构体变量
     *  struct <结构体名> {
     *      <变量类型> <成员名>;
     *      ...
     *  } 结构体变量名;
     *
     *  通过结构体变量创建结构体变量
     *  struct <结构体名> <结构体变量名>;
     * */
     typedef struct Company {
         char *name;
         char *id;
         char *location;
     } Company;

    typedef struct Person{
        char *name;
        int age;
        char *id;
        Company *company;
        struct {
            int extra;
            char *extra_str;
        } extra_str;
    } Person;

    Person person1 = {.name = "helisi", 23, "111122223333"};
    person1.company -> name = "xxxx";
    person1.company -> id = "1";
    person1.company -> location = "xxxx";
    person1.extra_str.extra = 1;
    person1.extra_str.extra_str = "extra_str";

    PRINT_INT(person1.age);
    person1.age = 32;

    PRINT_INT_HEX(&person1);

    Person *person_ptr = &person1;
    PRINT_STR(person_ptr -> name);
    PRINT_INT(person_ptr -> age);

    // 原始结构体大小 占用24字节
    PRINT_INT(sizeof(struct Person));
    PRINT_INT(sizeof(person1));

    /**
     *  匿名结构体
     *  直接使用结构体变量名初始化和使用
     * */
    struct {
        char *name;
        int age;
        char *id;
    }anonymous_person;

    return 0;
}