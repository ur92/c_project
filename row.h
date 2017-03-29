#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum addressingMode {IMMIDIATE, DIRECT, DIRECT_OFFSET,  DIRECT_REGISTER};
typedef enum addressingMode AddressingMode;

typedef struct row{
    int address;
    bool is_label;
    bool absolute;
    bool relative;
    bool external;
    AddressingMode op1_add;
    char *op1_value;
    AddressingMode op2_add;
    char *op2_value;
    char *command;
    char *label;
    int binary;

    struct row *next;
} *Row;

Row create_row(
        int address,
        bool is_label,
        bool absolute,
        bool relative,
        bool external,
        AddressingMode op1_add,
        char *op1_value,
        AddressingMode op2_add,
        char *op2_value,
        char *command,
        char *label,
        int binary
        );

#endif
