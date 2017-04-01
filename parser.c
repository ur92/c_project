#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"
#include "row.h"
#include "parser.h"
#include "symbol_list.h"
#include "helper.h"
#include "symbol.h"

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

void parse_lines(Memory mem, char lines[MEMORY_MAX][LINE_MAX],
		int number_of_lines) {
	int line_number;

	for (line_number = 0; line_number < number_of_lines; line_number++) {
		Row row = parse_line(mem, lines[line_number], line_number);

		if (row->is_command) {
			//add to comm lisd
		} else {
			//add to data list
		}

		if (row->is_labeled) {
			// push symbol

		}
	}
}

Row parse_line(char *line, int line_number) {
	bool is_labeled, is_command, command_segment;
	char segments[SEGMENTS_MAX][LINE_MAX], operands[OPERANDS_MAX];
	int i, number_of_segments, number_of_operands, row_length;
	Row row;
	AddressingMode operands_am[OPERANDS_MAX];

	number_of_segments = segmentize_line(segments, line);

	is_labeled = is_labeled(segments);
	is_command = is_command(segments[is_labeled ? 1 : 0]);

	if (is_labeled) {

	}

	if (is_command) {
		/* parse operands */
		number_of_operands = split_operands(operands,
				segments[is_labeled ? 2 : 1]);
		for (i = 0; i < number_of_operands; i++) {
			operands_am[i] = get_addressing_mode(operands[i]);
		}

		/* calc row/command length */
		row_length = get_row_length(operands_am);
	}

/*row = create_row(line_number,row_length, 0,is_labeled, is_command, )*/

return NULL;

}

int split_operands(char splitted[OPERANDS_MAX][LINE_MAX], char *segment) {
	char *token, *string, *tofree;
	int counter = 0;
	tofree = string = strdup(segment);

	while ((token = strsep(&string, ",")) != NULL) {
		strcpy(splitted[counter], token);
		counter++;
	}

	free(tofree);
	return counter;
}

bool is_labeled(char segments[SEGMENTS_MAX][LINE_MAX]) {
	if (strlen(segments[0]) > 0) {
		if (strchr(segments[0], LABEL_CHAR)) {
			return true;
		}
	}
	return false;
}

int find_row_length(char segments[SEGMENTS_MAX][LINE_MAX], bool is_labeled) {
	int operand_segment = is_labeled ? 2 : 1;

}

