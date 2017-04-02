#include <ctype.h>
#include <string.h>
#include "operand.h"
#include "helper.h"
#include "error.h"
#include "row.h"
#include "operand_def.h"

Operand create_operand(AddressingMode address_mode, char *value) {
	Operand this = (Operand) malloc(sizeof(struct operand));
	if (this) {
		this->address_mode = address_mode;
		this->value = str_dup(value);
	}
	return this;
}

AddressingMode get_addressing_mode(char *operand) {
	/*IMMIDIATE*/
	if (strchr(operand, IMMIDIATE_CHAR)) {
		return IMMIDIATE;
	}
	/*DIRECT_REGISTER*/
	if (operand[0] == 'r' && operand[1] >= '0' && operand[1] <= '7') {
		if (strchr(operand, DIRECT_OFFSET_START_CHAR)
				&& strchr(operand, DIRECT_OFFSET_END_CHAR)) {
			if (isdigit(operand[1]) && isdigit(operand[4])) {
				bool should_be_odd = (operand[1] - '0') % 2 != 0;
				bool should_be_even = (operand[4] - '0') % 2 == 0;
				if (should_be_odd && should_be_even)
					return DIRECT_OFFSET;
			}
			return -1;
		} else
			return DIRECT_REGISTER;
	}
	/* other are DIRECT*/
	return DIRECT;

	return -1;
}

int split_operands(char splitted[OPERANDS_MAX][LINE_MAX], char *segment) {
	char *token, *string, *tofree;
	int counter = 0;
	tofree = string = strdup(segment);

	while ((token = strsep(&string, ",")) != NULL) {
		strcpy(splitted[counter], token);
		counter++;
	}

	free(tofree);
	return counter;
}

int get_row_length(RowState state, Command command,
		Operand operands[OPERANDS_MAX], int number_of_operands) {
	int counter;
	if (state & IS_COMMAND) {
		counter = number_of_operands;

		if (counter == 2 && operands[0]->address_mode == DIRECT_REGISTER
				&& operands[1]->address_mode == DIRECT_REGISTER) {
			counter = 1;
		}
	}
	else if(state & IS_DATA_COMMAND){
		if(command==d_commands[DATA]){
			counter = number_of_operands;
		}
		else if(command==d_commands[STRING]){
			counter = strlen(operands[0])-2;
		}
	}

	return counter;
}
