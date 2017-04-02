#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "def.h"
#include "command.h"
#include "operand_def.h"
#include "row_def.h"

typedef struct row {
	int line_number;
	int length;
	int row_state;
	int address;
	int number_of_operands;
	Operand operands[DATA_OPERANDS_MAX];
	Command command;
	char *label;
	char binary[WORD_LENGTH];
	char segments[SEGMENTS_MAX][LINE_MAX];

	struct row *next;
}* Row;

Row create_row(int line_number, int length,int number_of_operands, RowState row_state, int address, Operand operands[OPERANDS_MAX],
		Command command, char *label, char binary[WORD_LENGTH], char segments[SEGMENTS_MAX][LINE_MAX]);

#endif
