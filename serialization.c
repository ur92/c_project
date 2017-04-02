#include <stdio.h>
#include <stdlib.h>
#include "row.h"
#include "row_def.h"
#include "helper.h"
#include "serialization.h"

char *serialize_command(Row row) {
	char binary[WORD_LENGTH] = "000000000000000";
	set_unused_bits(binary);
	set_aer_bits(binary, ABSOLUTE);
	set_opcode_bits(binary, row);

	return binary;
}

char *serialize_operand(Row row, Operand op) {
	if (row->command == d_commands[DATA]) {

	} else if (row->command == d_commands[STRING]) {

	}
}

void set_unused_bits(char binary[WORD_LENGTH]) {
	binary[14] = '1';
	binary[13] = '1';
	binary[12] = '1';
}

void set_opcode_bits(char binary[WORD_LENGTH], Row row) {
	char b_opcode[INT_BUF_SIZE];
	int_to_binary(row->command->opcode, b_opcode);
	binary[6] = b_opcode[0];
	binary[7] = b_opcode[1];
	binary[8] = b_opcode[2];
	binary[9] = b_opcode[3];
}

void set_aer_bits(char binary[WORD_LENGTH], AER aer) {
	binary[0] = '0';
	binary[1] = '0';

	switch (aer) {
	case 1:
		binary[0] = '1';
		break;
	case 2:
		binary[1] = '1';
		break;
	}
}

