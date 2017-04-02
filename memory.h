#ifndef MEMORY_H
#define MEMORY_H

#include "rows_list.h"
#include "symbols_list.h"

typedef struct memory {
	RowsList c_list;
	RowsList d_list;
	SymbolsList s_list;
	SymbolsList es_list;
	int ic;
	int dc;
} *Memory;

Memory init_memory();


#endif
