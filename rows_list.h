#ifndef ROWS_LIST_H
#define ROWS_LIST_H

#include "row.h"

typedef struct rowsList{
    Row head;
    Row current;
} *RowsList;

RowsList create_rows_list();

Row insert_row(RowsList list, Row prev, Row new_row);

Row push_row(RowsList list, Row new_row);

#endif
