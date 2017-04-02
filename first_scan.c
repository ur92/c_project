#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"

#include "first_scan.h"
#include "symbols_list.h"
#include "helper.h"
#include "symbol.h"
#include "memory.h"
#include "error.h"
#include "row.h"
#include "operand.h"

int segmentize_line(char segments[SEGMENTS_MAX][LINE_MAX], char *line) {
	/*char segments[SEGMENTS_MAX][LINE_MAX];*/
	int segment = 0;
	int i = 0, j = 0;
	int length = strlen(line);
	bool with_label = false;

	/*trim spaces*/
	while ((isspace(line[i]) || !isgraph(line[i])) && i < length)
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
	while ((isspace(line[i]) || !isgraph(line[i])) && i < length)
		i++;

	if (with_label) {
		/*second segment (command)*/
		j = 0;

		while ((!isspace(line[i]) && isgraph(line[i])) && i < length) {
			segments[segment][j] = line[i];
			i++;
			j++;
		}
		/*end the segment*/
		segments[segment][j] = '\0';
		segment++;
	}

	/*trim spaces*/
	while ((isspace(line[i]) || !isgraph(line[i])) && i < length)
		i++;

	/*second segment (operands)*/
	j = 0;
	while (i < length) {
		if (!isspace(line[i]) && isgraph(line[i])) {
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

void first_scan(Memory mem, char lines[MEMORY_MAX][LINE_MAX],
		int number_of_lines) {
	int line_number, address;
	Symbol symbol;

	for (line_number = 0; line_number <= number_of_lines; line_number++) {
		Row row = parse_line(lines[line_number], line_number);

		if (row) {
			if (row->row_state & IS_DATA_COMMAND) {
				if (row->row_state & IS_LABELED) {
					/* push symbol*/
					symbol = create_symbol(row->label, mem->dc, false, false,
							false);
					if (!push_symbol(mem->s_list, symbol)) {
						print_error(SYMBOL_ALREADY_EXIST, line_number);
					}
				}
				/*calc ref address*/
				address = BASE_MEM_ADDRESS + mem->dc;
				row->address = address;
				mem->dc += row->length;
				push_row(mem->d_list, row);
			}

			if (row->row_state & IS_ENT_EXT_COMMAND) {
				if (row->command == d_commands[EXTERN]) {
					/*add the symbol to external symbol list*/
					symbol = create_symbol(row->operands[0]->value, mem->ic,
							true, false, false);
					push_symbol(mem->es_list, symbol);
				} else {
					/*add the symbol to entry symbol list*/
					symbol = create_symbol(row->operands[0]->value, 0, false,
							true, false);
					push_symbol(mem->es_list, symbol);
				}
			}

			if (row->row_state & IS_COMMAND) {
				if (row->row_state & IS_LABELED) {
					/* push symbol*/
					symbol = create_symbol(row->label, mem->ic, false, false,
							true);
					if (!push_symbol(mem->s_list, symbol)) {
						print_error(SYMBOL_ALREADY_EXIST, line_number);
					}
				}
				/*calc the address*/
				address = BASE_MEM_ADDRESS + mem->ic;
				row->address = address;

				/*add to commands list*/
				push_row(mem->c_list, row);
				mem->ic += row->length;
			}

		}
	}
	update_data_symbols_address(mem->s_list, mem->ic);
	update_data_commands_address(mem->d_list, mem->ic);
}

Row parse_line(char *line, int line_number) {

	char segments[SEGMENTS_MAX][LINE_MAX],
			operands_strings[DATA_OPERANDS_MAX][LINE_MAX];
	int i, number_of_segments, number_of_operands, row_length;
	RowState row_state;
	Row row;
	AddressingMode address_mode;
	Operand operands[DATA_OPERANDS_MAX], op;
	Command command;

	number_of_segments = segmentize_line(segments, line);
	if (number_of_segments) {
		row_state = get_row_state(segments);

		/*if (row_state & IS_LABELED) {

		 }*/

		/* parse operands */
		number_of_operands = split_operands(operands_strings,
				segments[row_state & IS_LABELED ? 2 : 1]);

		/* get command */
		command = get_command(row_state,
				segments[(row_state & IS_LABELED) ? 1 : 0]);

		/*get operands*/
		for (i = 0; i < number_of_operands; i++) {
			if (row_state & IS_COMMAND) {
				/* get operand addressing mode */
				address_mode = get_addressing_mode(operands_strings[i]);
				if (address_mode == -1) {
					print_error(INVALID_ADDRESSING_MODE, line_number);
					address_mode = IMMIDIATE;
				}
			} else {
				address_mode = 0;
			}

			op = create_operand(address_mode, operands_strings[i]);
			operands[i] = op;
		}

		/*partial serialization*/
		if (row_state & IS_COMMAND) {

		} else if (row_state & IS_DATA_COMMAND) {
			/* is data */

		}

		/* calc row/command length */
		row_length = get_row_length(row_state, command, operands,
				number_of_operands);

		row = create_row(line_number, row_length, number_of_operands, row_state,
				0, operands, command,
				(row_state & IS_LABELED) ? segments[0] : "", 0, segments);

		return row;
	} else
		return NULL;
}

int get_row_state(char segments[SEGMENTS_MAX][LINE_MAX]) {

	int is_labeled, is_command, is_data_command, is_ent_ext_command;

	is_labeled = is_row_labeled(segments[0]);
	is_command = is_row_command(segments[is_labeled ? 1 : 0]);
	is_data_command = is_row_data_command(segments[is_labeled ? 1 : 0]);
	is_ent_ext_command = is_row_ent_ext_command(segments[is_labeled ? 1 : 0]);

	return (is_labeled | is_command | is_data_command | is_ent_ext_command);
}

bool is_row_labeled(char *segment) {
	if (strlen(segment) > 0) {
		if (strchr(segment, LABEL_CHAR)) {
			return IS_LABELED;
		}
	}
	return 0;
}

