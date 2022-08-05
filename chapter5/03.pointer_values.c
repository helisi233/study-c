//
// Created by helisi on 2022/8/5.
//
#include <stdio.h>
#include "include/Print_Utils.h"

int *pointer_at_large;

void DangerousPointer() {
    int a = 10;
    pointer_at_large = &a;
    // todo
    pointer_at_large = NULL;
}

int main(void) {

    int *p = NULL;
    if(p) {
        printf("if block");
    }else {
        printf("else block");
    }

    DangerousPointer();
    if(pointer_at_large) {
        // todo
    }

    return 0;
}