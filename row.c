#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "row.h"
#include "helper.h"
/*#include "operand.h"*/

Row create_row(int line_number, int length, int address, bool is_labeled,
		bool is_command, Operand operands[OPERANDS_MAX],
		char *command, char *label, int binary, char segments[SEGMENTS_MAX][LINE_MAX]) {
	int i;
	Row this = (Row) malloc(sizeof(struct row));
	if (this) {
		this->line_number = line_number;
		this->length = length;
		this->address = address;
		this->is_labeled = is_labeled;
		this->is_command = is_command;

		strcpy(this->command, command);
		this->label = str_dup(label);
		this->binary = binary;

		for(i=0; i<OPERANDS_MAX; i++){
		this->operands[i] = operands[i];
		}

		for(i=0; i<SEGMENTS_MAX; i++){
			strcpy(this->segments[i],segments[i]);
		}

		this->next = NULL;

	}

	return this;
}

