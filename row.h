#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "def.h"
#include "operand_def.h"
/*#include "operand.h"*/
#include "command.h"



typedef enum rowState{
	IS_LABELED = 1<<0,
	IS_COMMAND = 1<<1,
	IS_DATA_COMMAND = 1<<2,
	IS_ENT_EXT_COMMAND = 1<<3
} RowState;

typedef struct row {
	int line_number;
	int length;
	int row_state;
	int address;
	Operand operands[OPERANDS_MAX];
	Command command;
	char *label;
	int binary;
	char segments[SEGMENTS_MAX][LINE_MAX];

	struct row *next;
}* Row;

Row create_row(int line_number, int length,int row_state, int address, Operand operands[OPERANDS_MAX],
		Command command, char *label, int binary, char segments[SEGMENTS_MAX][LINE_MAX]);

#endif
