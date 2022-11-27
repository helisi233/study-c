//
// Created by helisi on 2022/8/8.
//
#include <stdio.h>
#include "include/Print_Utils.h"

#define OP_PRINT_INT 0
#define OP_PRINT_DOUBLE 1
#define OP_PRINT_STRING 2

typedef union Operand {
    int int_operand;
    double double_operand;
    char *string_operand;
}Operand;

typedef struct Instruction {
    int operator;
    Operand operand;
}Instruction;

void Process(Instruction *instruction) {
    switch (instruction -> operator) {
        case OP_PRINT_INT:
            PRINT_INT(instruction -> operand.int_operand);
            break;
        case OP_PRINT_DOUBLE:
            PRINT_DOUBLE(instruction -> operand.double_operand);
            break;
        case OP_PRINT_STRING:
            PRINT_STR(instruction -> operand.string_operand);
            break;
        default:
            fprintf(stderr, "unsuppored operator: %d\n", instruction -> operator);
    }
}

int main(void) {

    PRINT_INT(sizeof(Operand));

    Operand operand = {.int_operand=3, .double_operand=4.0};
    PRINT_INT(operand.int_operand);
    PRINT_DOUBLE(operand.double_operand);

    Instruction instruction = {
            .operator = OP_PRINT_STRING,
            .operand = {
                    .string_operand = "Hello World!"
            }
    };

    Process(&instruction);

    return 0;
}