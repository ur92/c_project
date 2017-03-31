#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "rows_list.h"
#include "row.h"



RowsList init_rows_list(){
    RowsList this= (RowsList)malloc(sizeof(struct rowsList));
    this->head = this->current = NULL;
    return this;
}

Row insert_row(RowsList list, Row prev, Row new_row){
    /*if the list is empty*/
    if(list->head == NULL){
          list->head = list->current = new_row;
    }
    else{
        /*insert the new row*/
        Row tmp = prev->next;
        prev->next = new_row;
        new_row->next= tmp;
    }
    /*update the current*/
    if(list->current->next != NULL){
        list->current = list->current->next;
    }
    return new_row;
}

Row push_row(RowsList list, Row new_row){
    return insert_row(list, list->current, new_row);
}
