#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "row.h"
#include "rows_list.h"

RowsList readFile(char *filename){
    RowsList list = create_rows_list();
    File *file = fopen(filename, "r");
    if(file){
        char line[MAX_LINE];
    
        while (fgets(line, sizeof(line), file)) {
            /* note that fgets don't strip the terminating \n, checking its
               presence would allow to handle lines longer that sizeof(line) */
            printf("%s", line); 
            
            Row row= parse_line(line);
            push_row(list, row);
        }
        /* may check feof here to make a difference between eof and io failure -- network
           timeout for instance */
    
        fclose(file);
    }
}

Row parse_line(char * line){
    
}







