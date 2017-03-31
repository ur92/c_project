#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "def.h"

typedef enum addressingMode {
	IMMIDIATE, DIRECT, DIRECT_OFFSET, DIRECT_REGISTER
} AddressingMode;

typedef struct row {
	int line_number;
	int length;
	int address;
	bool is_labeled;
	bool is_command;
	bool absolute;
	bool relative;
	bool external;
	AddressingMode op1_add;
	char *op1_value;
	AddressingMode op2_add;
	char *op2_value;
	char command[5];
	char *label;
	int binary;
	char segments[SEGMENTS_MAX][LINE_MAX];

	struct row *next;
}* Row;

Row create_row(
		int line_number,
		int length,
		int address,
		bool is_labeled,
		bool is_command,
		bool absolute,
		bool relative,
		bool external,
		AddressingMode op1_add,
		char *op1_value,
		AddressingMode op2_add,
		char *op2_value,
		char *command,
		char *label,
		int binary,
		char segments[SEGMENTS_MAX][LINE_MAX]
);

#endif
