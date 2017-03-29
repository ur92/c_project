#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "row.h"
#include "helper.h"

Row create_row(int address,
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
                ){

    Row this = (Row)malloc(sizeof(struct row));
    if(!this){
        this->address =address;
        this->is_label = is_label;
        this->absolute = absolute;
        this->relative = relative;
        this->external = external;
        this->op1_add = op1_add;
        this->op1_value = str_dup(op1_value);
        this->op2_add = op2_add;
        this->op2_value = str_dup(op1_value);
        this->command = str_dup(op1_value);
        this->label = str_dup(op1_value);
        this->binary = binary;
        this->next = NULL;
    }

    return this;
}

