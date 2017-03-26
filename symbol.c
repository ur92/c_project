#include <stdio.h>
#include <stdlib.h>

struck symbol{
    char *label;
    int address;
}

Symbol create_symbol(char * label, int address){
    Symbol this= malloc(sizeof(symbol));
    if(this != null){
        this->label = strdup(label);
        this->address = address;
    }
    
    return this;
}