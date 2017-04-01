#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "row.h"
#include "helper.h"

Row create_row(int line_number, int length, int address, bool is_labeled,
		bool is_command, bool absolute, Operand operands[OPERANDS_MAX],
		char *command, char *label, int binary, char *segments) {
	int i;
	Row this = (Row) malloc(sizeof(struct row));
	if (this) {
		this->line_number = line_number;
		this->length = length;
		this->address = address;
		this->is_labeled = is_labeled;
		this->is_command = is_command;
		this->operands = operands;
		this->command = str_dup(command);
		this->label = str_dup(label);
		this->binary = binary;
		this->segments = segments;

		this->next = NULL;

	}

	return this;
}

