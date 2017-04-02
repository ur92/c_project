#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/*#include "row.h"*/
#include "helper.h"
/*#include "operand.h"*/

Row create_row(int line_number, int length, int row_state, int address, Operand operands[DATA_OPERANDS_MAX],
		Command command, char *label, int binary, char segments[SEGMENTS_MAX][LINE_MAX]) {
	int i;
	Row this = (Row) malloc(sizeof(struct row));
	if (this) {
		this->line_number = line_number;
		this->length = length;
		this->address = address;
		this->row_state = row_state;

		this->command= command;
		this->label = str_dup(label);
		this->binary = binary;

		for(i=0; i<DATA_OPERANDS_MAX; i++){
		this->operands[i] = operands[i];
		}

		for(i=0; i<SEGMENTS_MAX; i++){
			strcpy(this->segments[i],segments[i]);
		}

		this->next = NULL;

	}

	return this;
}

