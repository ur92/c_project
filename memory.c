#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include "def.h"
#include "row.h"
#include "symbol.h"

struct memory {
    Row rows_list;
    Symbol symbols_list;
    Symbol externals_list;
    Symbol enteries_list;
};

#endif

