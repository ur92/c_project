#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "row.h"

enum addressingMode {IMMIDIATE, DIRECT, DIRECT_OFFSET,  DIRECT_REGISTER};

struct row{
    int address;
    bool is_label;
    bool absolute;
    bool relative;
    bool external;
    enum addressing_mode op1_add;
    char *op1_value;
    enum addressing_mode op2_add;
    char *op2_value;
    char *command;
    char *label;
    int binary;
    
    Row next;
};

Row create_row(int address, 
                bool is_label, 
                bool absolute,
                bool relative,
                bool external,
                Addressing_mode op1_add,
                char *op1_value,
                Addressing_mode op2_add,
                char *op2_value,
                char *command,
                char *label,
                int binary
                ){
        
    Row this = malloc(sizeof(row));
    if(this != null){
        this->address =address;
        this->is_label = is_label;
        this->absolute = absolute;
        this->relative = relative;
        this->external = external;
        this->op1_add = op1_add;
        this->op1_value = strdup(op1_value);
        this->op2_add = op2_add;
        this->op2_value = strdup(op1_value);
        this->command = strdup(op1_value);
        this->label = strdup(op1_value);
        this->binary = binary;
        this->next = NULL;
    }
    
    return this;
}

