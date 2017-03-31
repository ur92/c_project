#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"
#include "file_reader.h"
#include "rows_list.h"
#include "symbols_list.h"
#include "parser.h"
#include "memory.h"

int main(int argc, char **argv) {

	/*handle each input file*/
	for(int i=0; i< argc; i++){
		Memory mem = memory_init();

		char lines[MEMORY_MAX][LINE_MAX]= read_file("./ps.as");

	}

    printf("Sdfsd");

    return 0;
}
