#include <stdio.h>
#include <stdlib.h>

struct symbol{
    char *label;
    int address;
    Symbol next;
}

Symbol create_symbol(char * label, int address){
    Symbol this= malloc(sizeof(symbol));
    if(this != null){
        this->label = strdup(label);
        this->address = address;
        this->next = NULL ;
    }
    
    return this;
}

Symbol add_symbol(Symbol prev){
    
}