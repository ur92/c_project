#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"
#include "file_reader.h"
#include "file_writer.h"
#include "rows_list.h"
#include "symbols_list.h"
#include "first_scan.h"
#include "memory.h"
#include "command.h"

int main(int argc, char **argv) {

	int i;
	char lines[MEMORY_MAX][LINE_MAX];

	Memory mem;


	init_commands();

	/*handle each input file*/
	for (i = 1; i < argc; i++) {
		mem = init_memory();

		int number_of_lines = read_file(lines, argv[i]);
		if (number_of_lines > -1) {
			first_scan(mem, lines, number_of_lines);
			second_scan(mem);

			write_ob_file(mem, argv[i]);
			write_ext_file(mem, argv[i]);
			write_ent_file(mem, argv[i]);
		}
	}
	return EXIT_SUCCESS;
}
