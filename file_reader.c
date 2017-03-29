#include <stdio.h>
#include "rows_list.h"
#include "def.h"
#include "parser.h"


RowsList read_file(char *path){
    RowsList list = create_rows_list();
    FILE *file = fopen(path, "r");
    if(file){
        char line[LINE_MAX];
    
        while (fgets(line, sizeof(line), file)) {
            Row r= parse_line(line);
            if(r){
                push_row(list, r);
            }
        }
        fclose(file);
    }
    return list;
}











