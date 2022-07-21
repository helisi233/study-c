//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>

int main(void) {

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define REM '%'
    int left, right;
    char operator;
    char command = 'y';
    while(command != 'q') {
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

        puts("Again? Type 'q' for quit:\n");
        command = getchar();
    }

    int sum = 0;
    for (int i = 0; i <= 100; ++i) {
        sum += i;
    }
    printf("sum of [1, 100]: %d\n", sum);

    int sumij = 0;
    for (int i = 0, j = 0; i <= 100, j <= 100; ++i, ++j) {
        sumij += i * (i + j);
    }
    printf("sumij: %d\n", sumij);

    for (int i = 0; i < 10; ++i) {
        if(i == 2)
            continue;
        if(i == 8)
            break;
        printf("i: %d\n", i);
    }

    return 0;
}