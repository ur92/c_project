#include <stdlib.h>
#include "memory.h"
#include "def.h"

struck memory {
    Row rows[MEMORY_MAX];
    Symbol symbols[MEMORY_MAX];
    Symbol externals[MEMORY_MAX];
    Symbol enteries[MEMORY_MAX];
};

