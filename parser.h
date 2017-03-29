#ifndef PARSER_H
#define PARSER_H
#include "row.h"

Row parse_line(char *line);
int segmentize_line(char segments[SEGMENTS_MAX][LINE_MAX], char *line);

#endif