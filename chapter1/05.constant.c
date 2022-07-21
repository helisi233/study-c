//
// Created by helisi on 2022/7/21.
//
#include <stdio.h>

#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE 0x0000FF

int main(void) {

    const int kRed = 0xFF0000;
    const int kGreen = 0x00FF00;
    const int kBlue = 0x0000FF;

    printf("kRed: %d\n", kRed);

    int *p_kRed = &kRed;
    *p_kRed = 0;

    printf("kRed: %d\n", kRed);

    printf("COLOR_RED: %d\n", COLOR_RED);


    return 0;
}