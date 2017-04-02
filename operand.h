#ifndef OPERNAD_H
#define OPERAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "row.h"
#include "operand_def.h"
#include "command.h"



Operand create_operand(AddressingMode address_mode, char *value);
AddressingMode get_addressing_mode(char *operand);
int split_operands(char splitted[DATA_OPERANDS_MAX][LINE_MAX], char *segment) ;
int get_row_length(RowState state, Command command,
		Operand operands[OPERANDS_MAX], int number_of_operands);


#endif
