#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "symbol.h"
#include "def.h"

Symbol create_symbol(char * label, int address, DataCommandName type){
    Symbol this= (Symbol)malloc(sizeof(struct symbol));
    if(this){
    	if(strchr(label, LABEL_CHAR)){
    		label[strlen(label)-1]='\0';
    	}
        this->label = strdup(label);
        this->address = address;
        this->type = type;
        this->next = NULL ;
    }

    return this;
}

