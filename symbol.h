#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct symbol{
    char *label;
    int address;
    struct symbol *next;
} *Symbol;

Symbol create_symbol(char * label, int address);


#endif
