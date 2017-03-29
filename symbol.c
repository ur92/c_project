#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "symbol.h"

Symbol create_symbol(char * label, int address){
    Symbol this= (Symbol)malloc(sizeof(struct symbol));
    if(!this){
        this->label = str_dup(label);
        this->address = address;
        this->next = NULL ;
    }

    return this;
}

/*Symbol add_symbol(Symbol prev){

}*/