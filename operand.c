#include "operand.h"
#include "helper.h"
#include "error.h"

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
	if(strchr(operand, IMMIDIATE_CHAR)){
		return IMMIDIATE;
	}

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

int get_row_length(AddressingMode operands_am[OPERANDS_MAX]) {

}
