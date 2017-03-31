#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include "def.h"
#include "row.h"
#include "symbol.h"
#include "memory.h"


Memory init_memory(){
	Memory this= (Memory)malloc(sizeof(struct memory));
	    this->c_list = init_rows_list();
	    this->d_list = init_rows_list();
	    this->s_list = init_symbols_list();
	    return this;
}

#endif

