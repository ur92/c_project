#include <stdio.h>
#include <stdlib.h>
#include "row.h"
#include "row_def.h"
#include "helper.h"
#include "serialization.h"

char *serialize_command(char binary[WORD_LENGTH], Row row) {
	int i;
	binary = EMPTY_WORD;
	set_unused_bits(binary);
	set_aer_bits(binary, ABSOLUTE);
	set_opcode_bits(binary, row);

	for (i = 0; i < row->number_of_operands; i++) {
		set_address_mode_bits(binary, row->operands, i);
	}

	return binary;
}

char *serialize_operand(char binary[WORD_LENGTH], Row row, Operand op) {
	binary = EMPTY_WORD;
	if (row->row_state & IS_COMMAND) {

	}
	return binary;
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

void set_address_mode_bits(char binary[WORD_LENGTH],
		Operand operands[OPERANDS_MAX], int operand_index) {
	char l = '0', r = '0';

	switch (operands[operand_index]->address_mode) {
	case DIRECT:
		r = '1';
		l = '0';
		break;
	case DIRECT_OFFSET:
		r = '0';
		l = '1';
		break;
	case DIRECT_REGISTER:
		r = '1';
		l = '1';
		break;
	case IMMIDIATE:
		r = '0';
		l = '0';
		break;
	}
	if (operand_index == 0) {
		binary[2] = r;
		binary[3] = l;
	} else {
		binary[4] = r;
		binary[5] = l;
	}
}

void set_aer_bits(char binary[WORD_LENGTH], AER aer) {
	binary[0] = '0';
	binary[1] = '0';

	switch (aer) {
	case 0:
		break;
	case 1:
		binary[0] = '1';
		break;
	case 2:
		binary[1] = '1';
		break;
	}
}

