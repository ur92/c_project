#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include "row.h"
#include "memory.h"

Row parse_line(char *line, int line_number);

int segmentize_line(char segments[SEGMENTS_MAX][LINE_MAX], char *line);
void parse_lines(Memory mem, char lines[MEMORY_MAX][LINE_MAX],
		int number_of_lines);
Row parse_line(char *line, int line_number);
int get_row_state(char segments[SEGMENTS_MAX][LINE_MAX]);
bool is_row_labeled(char *segment);

#endif
