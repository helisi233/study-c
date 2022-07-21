//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>
#include <stdbool.h>

int main(void) {

#define MAGIC_NUMBER 10
    int user_input;
    printf("Please input a number: \n");
    scanf("%d", &user_input);
    if(user_input > MAGIC_NUMBER) {
        printf("your number is bigger\n");
    }else if(user_input < MAGIC_NUMBER) {
        printf("your number is smaller\n");
    }else {
        printf("yes\n");
    }

    bool is_enable = true;
    bool is_visible = false;
    if(is_enable) {
        if(is_visible) {
            printf("enable and visible\n");
        }else {
            printf("enable not visible\n");
        }
    }
    bool is_open = is_enable && is_visible ? 1 : 0;
    printf("is_open: %d\n", is_open);

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define REM '%'
    int left,right;
    char operator;
    printf("Please input left operator right\n");
    scanf("%d %c %d", &left, &operator, &right);
    int result;
    switch (operator) {
        case ADD:
            result = left + right;
            break;
        case SUB:
            result = left - right;
            break;
        case MUL:
            result = left * right;
            break;
        case DIV:
            result = left / right;
            break;
        case REM:
            result = left % right;
            break;
        default:
            printf("unsupport operator: %c", operator);
            return 1;
    }
    printf("result: %d\n", result);

    return 0;
}