//
// Created by helisi on 2022/7/25.
//
#include <stdio.h>

#define MAX(a, b) a > b ? a : b
#define MAX2(a, b) (a) > (b) ? (a) : (b)

#define IS_HEX_CHARACTER(ch) \
((ch) >= '0' && (ch) <= '9') || \
((ch) >= 'a' && (ch) <= 'z') || \
((ch) >= 'A' && (ch) <= 'Z')

int main(void) {
    int max = MAX(1, 3);
    printf("%d\n", max);

    int max2 = MAX2(1, MAX2(3, 4));
    printf("%d\n", max2);

    int is_hex_character = IS_HEX_CHARACTER('a');
    printf("%d\n", is_hex_character);
    printf("%d\n", IS_HEX_CHARACTER('*'));

    return 0;
}