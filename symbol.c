#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "helper.h"
#include "symbol.h"
#include "def.h"

Symbol create_symbol(char * label, int address, bool is_external, bool is_command){
    Symbol this= (Symbol)malloc(sizeof(struct symbol));
    if(this){
    	if(strchr(label, LABEL_CHAR)){
    		label[strlen(label)-1]='\0';
    	}
        this->label = strdup(label);
        this->address = address;
        this->is_external = is_external;
        this->is_command = is_command;
        this->next = NULL ;
    }

    return this;
}

