#include <stdio.h>
#include "rows_list.h"
#include "def.h"
#include "parser.h"
#include "error.h"


int read_file(char lines[MEMORY_MAX][LINE_MAX], char *path){

    FILE *file = fopen(path, "r");
    char line[LINE_MAX];
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
    	print_error(FILE_ERROR,0);
    }
    return counter;
}











