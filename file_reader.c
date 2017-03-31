#include <stdio.h>
#include "rows_list.h"
#include "def.h"
#include "parser.h"


RowsList read_file(char *path){

    FILE *file = fopen(path, "r");
    char lines[MEMORY_MAX][LINE_MAX];
    char *line;
    int counter =0;

    if(file){
        while (fgets(line, sizeof(line), file)) {
            strncpy(lines[counter], line, LINE_MAX);
        }
        fclose(file);
    }
    return lines;
}











