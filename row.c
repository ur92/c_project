#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "row.h"
#include "helper.h"
#include "def.h"
#include "serialization.h"
/*#include "operand.h"*/

Row create_row(int line_number, int length, int number_of_operands,
		RowState row_state, int address, Operand operands[DATA_OPERANDS_MAX],
		Command command, char *label, char segments[SEGMENTS_MAX][LINE_MAX]) {
	int i;
	Row this = (Row) malloc(sizeof(struct row));
	if (this) {
		this->line_number = line_number;
		this->length = length;
		this->number_of_operands = number_of_operands;
		this->address = address;
		this->row_state = row_state;

		this->command = command;
		this->label = malloc(strlen(label) + 1);
		strcpy(this->label, label);


		for (i = 0; i < number_of_operands; i++) {
			this->operands[i] = operands[i];
		}

		for (i = 0; i < SEGMENTS_MAX; i++) {
			strcpy(this->segments[i], segments[i]);
		}

		if(this->row_state&IS_COMMAND)
			this->binary= strdup(serialize_command(this));
		else
			this->binary =strdup(EMPTY_WORD);

		this->next = NULL;

	}

	return this;
}

