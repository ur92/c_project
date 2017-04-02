#ifndef ROWS_LIST_H
#define ROWS_LIST_H

#include "row.h"


typedef struct rowsList{
    Row head;
    Row current;
} *RowsList;

RowsList init_rows_list();

Row insert_row(RowsList list, Row prev, Row new_row);

Row push_row(RowsList list, Row new_row);

RowsList concat_lists(RowsList list1, RowsList list2);
void update_data_commands_address(RowsList list, int ic);

#endif
