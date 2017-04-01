#include "operand.h"
#include "helper.h"

Operand create_operand(AddressingMode address_mode, int aer, char *value) {
	Operand this = (Operand) malloc(sizeof(struct operand));
	if (this) {
		this->address_mode = address_mode;
		this->aer = aer;
		this->value = str_dup(value);
	}
	return this;
}

AddressingMode get_addressing_mode(char *operand) {

}

int get_row_length(AddressingMode operands_am[OPERANDS_MAX]) {

}

