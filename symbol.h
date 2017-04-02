#ifndef SYMBOL_H
#define SYMBOL_H

#include "command.h"

typedef struct symbol{
    char *label;
    int address;
    DataCommandName type;
    struct symbol *next;
} *Symbol;

Symbol create_symbol(char * label, int address, DataCommandName type);


#endif
