#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"
#include "row.h"
#include "rows_list.h"

RowsList readFile(char *filename){
    RowsList list = create_rows_list();
    File *file = fopen(filename, "r");
    if(file){
        char line[LINE_MAX];
    
        while (fgets(line, sizeof(line), file)) {
            Row row= parse_line(line);
            if(row){
                push_row(list, row);
            }
        }
        fclose(file);
    }
}











