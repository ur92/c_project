#ifndef SYMBOLS_LIST_H
#define SYMBOLS_LIST_H

#include "symbol.h"

typedef struct symbolsList {
	Symbol head;
	Symbol current;
} *SymbolsList;


SymbolsList init_symbols_list();
Symbol symbol_search(SymbolsList list, char *label);
bool is_exist(SymbolsList list, char *label);
Symbol push_symbol(SymbolsList list, Symbol new_symbol);
void update_data_symbols_address(SymbolsList list,int ic);

#endif
