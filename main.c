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

	int i;
	/*handle each input file*/
	for (i = 0; i < argc; i++) {
		Memory mem = init_memory();

		char lines[MEMORY_MAX][LINE_MAX];
		int number_of_lines = read_file(lines, "./ps.as");
		if (number_of_lines > -1) {
			parse_lines(mem, lines, number_of_lines);
		}

	}

	printf("Sdfsd");

	return 0;
}
