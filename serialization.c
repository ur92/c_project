#include <stdio.h>
#include <stdlib.h>
#include "row.h"
#include "row_def.h"
#include "helper.h"
#include "serialization.h"

char *serialize_command(Row row) {
	int i;
	long int l;
	char *mirror_str = strdup(EMPTY_WORD);

	set_unused_bits(mirror_str);
	set_aer_bits(mirror_str, ABSOLUTE);
	set_opcode_bits(mirror_str, row);
	set_group_bits(mirror_str, row);

	for (i = 0; i < row->number_of_operands; i++) {
		set_address_mode_bits(mirror_str, row->operands, i);
	}

	reverse(mirror_str);

	return mirror_str;
}

char *serialize_operand(char binary[WORD_LENGTH], Row row, Operand op) {
	binary = EMPTY_WORD;
	if (row->row_state & IS_COMMAND) {

	}
	return binary;
}

char * set_unused_bits(char binary[WORD_LENGTH]) {

	binary[14] = '1';
	binary[13] = '1';
	binary[12] = '1';
	return binary;
}

char * set_opcode_bits(char binary[WORD_LENGTH], Row row) {
	char b_opcode[INT_BUF_SIZE];

	int_to_binary(row->command->opcode, b_opcode);
	binary[6] = b_opcode[INT_BUF_SIZE - 2];
	binary[7] = b_opcode[INT_BUF_SIZE - 3];
	binary[8] = b_opcode[INT_BUF_SIZE - 4];
	binary[9] = b_opcode[INT_BUF_SIZE - 5];
	return binary;
}

char * set_address_mode_bits(char binary[WORD_LENGTH],
		Operand operands[OPERANDS_MAX], int operand_index) {

	int l = 5, r = 4;
	if (operand_index == 1) {
		r = 2;
		l = 3;
	}

	switch (operands[operand_index]->address_mode) {
	case DIRECT:
		binary[r] = '1';
		binary[l] = '0';
		break;
	case DIRECT_OFFSET:
		binary[r] = '0';
		binary[l] = '1';
		break;
	case DIRECT_REGISTER:
		binary[r] = '1';
		binary[l] = '1';
		break;
	case IMMIDIATE:
		binary[r] = '0';
		binary[l] = '0';
		break;
	}

	return binary;
}

char * set_aer_bits(char binary[WORD_LENGTH], AER aer) {
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

	return binary;
}

char * set_group_bits(char binary[WORD_LENGTH], Row row){
	binary[10]='0';
	binary[11]='0';
	if(row->number_of_operands==1){
		binary[10]='1';
	}
	else if(row->number_of_operands==2){
		binary[11]='1';
	}
	return binary;
}

