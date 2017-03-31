

#include <stdlib.h>
#include "memory.h"
#include "def.h"
#include "row.h"
#include "symbol.h"


Memory init_memory(){
	Memory this= (Memory)malloc(sizeof(struct memory));
	    this->c_list = init_rows_list();
	    this->d_list = init_rows_list();
	    this->s_list = init_symbols_list();
	    this->ic =0;
	    this->dc =0;

	    return this;
}


