//
// Created by helisi on 2022/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/Print_Util.h"

void SwapElement(int array[], int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

void ShuffleArray(int array[], int length) {
    srand(time(NULL));
    for (int i = length-1; i > 0; --i) {
        int random_number = rand() % length;
        SwapElement(array, i, random_number);
    }
}

int main(void) {

#define PLAYER_COUNT 20
    int players[PLAYER_COUNT];
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        players[i] = i;
    }
    Print_Int_Array(players, PLAYER_COUNT);

    ShuffleArray(players, PLAYER_COUNT);
    Print_Int_Array(players, PLAYER_COUNT);

    return 0;
}