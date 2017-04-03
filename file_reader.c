#include <stdio.h>
#include <string.h>
#include "rows_list.h"
#include "def.h"
#include "first_scan.h"
#include "error.h"

int read_file(char lines[MEMORY_MAX][LINE_MAX], char *file_name) {

	FILE *file;
	char line[LINE_MAX], path[LINE_MAX];
	int counter = 0;

	strcpy(path, file_name);
	strcat(path, ".as");

	file = fopen(path, "r");
	if (file) {
		while (fgets(line, sizeof(line), file)) {
			counter++;
			strncpy(lines[counter], line, LINE_MAX);
		}
		fclose(file);
	} else {
		/*file error*/
		print_error(FILE_ERROR, 0);
		return -1;
	}
	return counter;
}

