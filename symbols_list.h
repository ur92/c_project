#ifndef SYMBOLS_LIST_H
#define SYMBOLS_LIST_H

#include "symbol.h"

typedef struct symbolsList{
	Symbol head;
	Symbol current;
}* SymbolsList;

#endif
