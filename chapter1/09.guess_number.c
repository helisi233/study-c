//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));
    int magic_number = rand();

    char command = 'y';
    int user_input;
    while('q' != command) {
        printf("Please input your number\n");
        scanf("%d", &user_input);
        if(user_input < magic_number) {
            printf("your number is smaller\n");
        }else if(user_input > magic_number) {
            printf("your number is bigger\n");
        }else {
            printf("yes\n");
        }

        printf("Again? type 'q' for quit");
        command = getchar();
    }

    return 0;
}