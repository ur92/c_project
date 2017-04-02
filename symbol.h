#ifndef SYMBOL_H
#define SYMBOL_H
#include <stdbool.h>
#include "command.h"

typedef struct symbol{
    char *label;
    int address;
    bool is_external;
    bool is_entry;
    bool is_command;
    struct symbol *next;
} *Symbol;

Symbol create_symbol(char * label, int address, bool is_external, bool is_entry, bool is_command);

#endif
