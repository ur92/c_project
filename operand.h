#ifndef OPERNAD_H
#define OPERAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "def.h"

#define _12 DIRECT&DIRECT_OFFSET
#define _123 _12&DIRECT_REGISTER
#define _0123 IMMIDIATE&_123

typedef enum aer {
	ABSOLUTE = 0, EXTERNAL = 1, RELATIVE = 2
} AER;

typedef enum addressingMode {
	IMMIDIATE = 1 << 0,
	DIRECT = 1 << 1,
	DIRECT_OFFSET = 1 << 2,
	DIRECT_REGISTER = 1 << 3
} AddressingMode;

typedef struct operand {
	AddressingMode address_mode;
	AER aer;
	char *value;
}* Operand;

Operand create_operand(AddressingMode address_mode, char *value);
AddressingMode get_addressing_mode(char *operand);
int split_operands(char splitted[OPERANDS_MAX][LINE_MAX], char *segment);
int get_row_length(Operand operands[OPERANDS_MAX], int number_of_operands);

#endif
