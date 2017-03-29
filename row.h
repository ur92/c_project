#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct row *Row;
enum addressingMode {IMMIDIATE, DIRECT, DIRECT_OFFSET,  DIRECT_REGISTER};

Row create_row(
        int address, 
        bool is_label, 
        bool absolute,
        bool relative,
        bool external,
        enum addressingMode op1_add,
        char *op1_value,
        enum addressingMode op2_add,
        char *op2_value,
        char *command,
        char *label,
        int binary
        );
        
#endif
