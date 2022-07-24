//
// Created by helisi on 2022/7/24.
//
#include <stdio.h>

void Move(int n, char src, char dest, char tmp) {
    if(n == 0) {
        return;
    }else if(n == 1) {
        printf("%c ---> %c\n", src, dest);
    }else {
        Move(n-1, src, tmp, dest);
        Move(1, src, dest, tmp);
        Move(n-1, tmp, dest, src);
    }
}

int main(void) {
    Move(3, 'A', 'B', 'C');
    return 0;
}