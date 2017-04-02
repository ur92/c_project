#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include "row.h"

Row parse_line(char *line, int line_number);
bool is_row_labeled(char segments[SEGMENTS_MAX][LINE_MAX]);
int segmentize_line(char segments[SEGMENTS_MAX][LINE_MAX], char *line);

#endif
