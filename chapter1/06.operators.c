//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>

int main(void) {

    int left, right;
    left = 2;
    right = 3;

    int sum = left + right;
    int diff = left = right;
    int product = left * right;
    int quotient = left / right;
    float quotient_float = right * 1.f / left;
    int remainder = left % right;

    printf("sum: %d\n", sum);
    printf("diff: %d\n", diff);
    printf("product: %d\n", product);
    printf("quotient: %d\n", quotient);
    printf("quotient_float: %f\n", quotient_float);
    printf("remainder: %d\n", remainder);

    printf("3 > 2: %d\n", 3 > 2);
    printf("3 < 2: %d\n", 3 < 2);
    printf("3 >= 2: %d\n", 3 >= 2);
    printf("3 <= 2: %d\n", 3 <= 2);
    printf("3 == 2: %d\n", 3 == 2);
    printf("3 != 2: %d\n", 3 != 2);

    printf("3 > 2 && 3 < 2: %d\n", 3 > 2 && 3 < 2);
    printf("3 > 2 || 3 < 2: %d\n", 3 > 2 || 3 < 2);

    int i = 1;
    int j = i++;
    int k = ++i;
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    printf("k: %d\n", k);

#define FLAG_VISIBLE 1 << 0        // 0001
#define FLAG_TRANSPARENT 1 << 1    // 0010
#define FLAG_RESIZABLE 1 << 2      // 0100
    int window_flags = FLAG_VISIBLE | FLAG_TRANSPARENT | FLAG_RESIZABLE;    // 0111
    int resizable = FLAG_RESIZABLE & window_flags;
    printf("is resizable: %d\n", resizable);

    return 0;
}