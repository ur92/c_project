#include <stdio.h>
#include "rows_list.h"
#include "def.h"
#include "parser.h"


int read_file(char lines[MEMORY_MAX][LINE_MAX], char *path){

    FILE *file = fopen(path, "r");
    char *line;
    int counter =-1;

    if(file){
        while (fgets(line, sizeof(line), file)) {
        	counter++;
            strncpy(lines[counter], line, LINE_MAX);
        }
        fclose(file);
    }
    else{
    	/*file error*/
    }
    return counter;
}











