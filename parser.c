#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"
#include "row.h"
#include "parser.h"

int segmentize_line(char segments[SEGMENTS_MAX][LINE_MAX], char *line) {
	/*char segments[SEGMENTS_MAX][LINE_MAX];*/
	int segment = 0;
	int i = 0, j = 0;
	int length = strlen(line);
	bool with_label = false;

	/*trim spaces*/
	while (isspace(line[i]) && i < length)
		i++;

	/*empty line*/
	if (i == length)
		return 0;

	/*coment line*/
	if (line[i] == COMMENT_CHAR)
		return 0;

	/*first segment (label or command)*/
	while (!isspace(line[i]) && i < length) {
		segments[segment][j] = line[i];
		i++;
		j++;
	}

	/*end the segment*/
	segments[segment][j] = '\0';

	if (strlen(segments[segment]) > 0) {
		if (strchr(segments[segment], LABEL_CHAR)) {
			with_label = true;
		}
	}

	segment++;

	/*trim spaces*/
	while (isspace(line[i]) && i < length)
		i++;

	if (with_label) {
		/*second segment (command)*/
		j = 0;

		while (!isspace(line[i]) && i < length) {
			segments[segment][j] = line[i];
			i++;
			j++;
		}
		/*end the segment*/
		segments[segment][j] = '\0';
		segment++;
	}

	/*trim spaces*/
	while (isspace(line[i]) && i < length)
		i++;

	/*second segment (operands)*/
	j = 0;
	while (i < length) {
		if (!isspace(line[i])) {
			segments[segment][j] = line[i];
			j++;
		}
		i++;
	}
	/*end the segment*/
	segments[segment][j] = '\0';
	segment++;

	return segment;
}

Row parse_line(char *line) {
	bool is_labeled, is_command;
	char segments[SEGMENTS_MAX][LINE_MAX];
	Row row;

	int number_of_segments = segmentize_line(segments, line);
	is_labeled = is_labeled(segments);
	is_command = is_command(segments);

	if(is_command){
		// parse operands
	}

	row = create_row(0, with_label, false, false, false, IMMIDIATE, "asd",
			IMMIDIATE, "asdd", "comm", "label", 0);

	return row;

}

bool is_labeled(char segments[SEGMENTS_MAX][LINE_MAX]) {
	if (strlen(segments[0]) > 0) {
		if (strchr(segments[0], LABEL_CHAR)) {
			return true;
		}
	}
	return false;
}

