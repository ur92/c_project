#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "row.h"
#include "row_def.h"
#include "helper.h"
#include "serialization.h"
#include "symbols_list.h"

char *serialize_command(Row row) {
	int i;
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

char *set_direct(char binary[WORD_LENGTH], Operand op, SymbolsList list) {
	int address, i;
	char direct_address[INT_BUF_SIZE];

	address = get_symbol_address(op->value, list);
	int_to_binary(address, direct_address);

	binary[0] = '0';
	binary[1] = '1';
	for (i = 2; i < WORD_LENGTH - 2; i++) {
		binary[i] = direct_address[INT_BUF_SIZE - i];
	}

	return binary;
}

char *serialize_operand_one_row(Row row) {
	char *mirror_str = strdup(EMPTY_WORD);
	set_direct_register(mirror_str, row->operands[0], true);
	set_direct_register(mirror_str, row->operands[1], false);

	reverse(mirror_str);
	return mirror_str;
}

char *set_immidiate(char binary[WORD_LENGTH], Operand op) {
	char immidiate[INT_BUF_SIZE];
	char *tmp = strdup(op->value);
	int num, i;
	bool data = true;

	if (tmp[0] == '#') {
		tmp[0] = ' ';
		data = false;
	}
	num = strtol(tmp, NULL, 10);
	int_to_binary(num, immidiate);

	for (i = data ? 0 : 2; i < WORD_LENGTH - 1; i++) {
		binary[i] = immidiate[INT_BUF_SIZE - i - (data ? 2 : 0)];
	}

	return binary;
}

char *set_direct_offset(char binary[WORD_LENGTH], Operand op) {
	char dr1[INT_BUF_SIZE], dr2[INT_BUF_SIZE];
	int_to_binary(op->value[1] - '0', dr1);
	int_to_binary(op->value[4] - '0', dr2);
	binary[2] = dr1[INT_BUF_SIZE - 2];
	binary[3] = dr1[INT_BUF_SIZE - 3];
	binary[4] = dr1[INT_BUF_SIZE - 4];
	binary[5] = dr1[INT_BUF_SIZE - 5];
	binary[6] = dr1[INT_BUF_SIZE - 6];
	binary[7] = dr1[INT_BUF_SIZE - 7];

	binary[8] = dr2[INT_BUF_SIZE - 2];
	binary[9] = dr2[INT_BUF_SIZE - 3];
	binary[10] = dr2[INT_BUF_SIZE - 4];
	binary[11] = dr2[INT_BUF_SIZE - 5];
	binary[12] = dr2[INT_BUF_SIZE - 6];
	binary[13] = dr2[INT_BUF_SIZE - 7];

	return binary;
}

char *set_direct_register(char binary[WORD_LENGTH], Operand op, bool is_dest) {
	char direct_register[INT_BUF_SIZE];
	int_to_binary(op->value[1] - '0', direct_register);

	if (is_dest) {
		binary[8] = direct_register[INT_BUF_SIZE - 2];
		binary[9] = direct_register[INT_BUF_SIZE - 3];
		binary[10] = direct_register[INT_BUF_SIZE - 4];
		binary[11] = direct_register[INT_BUF_SIZE - 5];
		binary[12] = direct_register[INT_BUF_SIZE - 6];
		binary[13] = direct_register[INT_BUF_SIZE - 7];
	} else {
		binary[2] = direct_register[INT_BUF_SIZE - 2];
		binary[3] = direct_register[INT_BUF_SIZE - 3];
		binary[4] = direct_register[INT_BUF_SIZE - 4];
		binary[5] = direct_register[INT_BUF_SIZE - 5];
		binary[6] = direct_register[INT_BUF_SIZE - 6];
		binary[7] = direct_register[INT_BUF_SIZE - 7];

	}
	return binary;
}

char *serialize_operand(SymbolsList list, Row row, int operand_num) {
	char *mirror_str = strdup(EMPTY_WORD);
	Operand op = row->operands[operand_num];

	switch (op->address_mode) {
	case NO_ADDRESS:
	case IMMIDIATE:
		set_immidiate(mirror_str, op);
		break;
	case DIRECT:
		set_direct(mirror_str, op, list);
		break;
	case DIRECT_REGISTER:
		set_direct_register(mirror_str, op,
				((operand_num == 0) ? true : false));
		break;
	case DIRECT_OFFSET:
		set_direct_offset(mirror_str, op);
		break;
	}
	reverse(mirror_str);
	return mirror_str;
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
	case NO_ADDRESS:
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

char * set_group_bits(char binary[WORD_LENGTH], Row row) {
	binary[10] = '0';
	binary[11] = '0';
	if (row->number_of_operands == 1) {
		binary[10] = '1';
	} else if (row->number_of_operands == 2) {
		binary[11] = '1';
	}
	return binary;
}

