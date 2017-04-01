#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "def.h"
#include "command.h"
/*#include "operand.h"*/

typedef struct row {
	int line_number;
	int length;
	int address;
	bool is_labeled;
	bool is_command;
	/*Operand operands[OPERANDS_MAX];*/
	char command[5];
	char *label;
	int binary;
	char segments[SEGMENTS_MAX][LINE_MAX];

	struct row *next;
}* Row;

Row create_row(int line_number, int length, int address, bool is_labeled,
		bool is_command/*, Operand operands[OPERANDS_MAX]*/, char *command,
		char *label, int binary, char segments[SEGMENTS_MAX][LINE_MAX]);

#endif
