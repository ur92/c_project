#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"
#include "rows_list.h"
#include "file_reader.h"

RowsList read_file(char *filename){
    RowsList list = create_rows_list();
    File *file = fopen(filename, "r");
    if(file){
        char line[LINE_MAX];
    
        while (fgets(line, sizeof(line), file)) {
            Row r= parse_line(line);
            if(r){
                push_row(list, r);
            }
        }
        fclose(file);
        return list;
    }
}











