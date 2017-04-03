#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <stdio.h>
#include "row.h"

char *serialize_command(Row row);

char *serialize_operand(char binary[WORD_LENGTH], Row row, Operand op);

char *  set_unused_bits(char binary[WORD_LENGTH]);
char *  set_opcode_bits(char binary[WORD_LENGTH], Row row);
char *  set_aer_bits(char binary[WORD_LENGTH],AER aer);
char * set_address_mode_bits(char binary[WORD_LENGTH],
		Operand operands[OPERANDS_MAX], int operand_index);
char * set_group_bits(mirror_str, row);

#endif


