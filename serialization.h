#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <stdio.h>
#include "row.h"
#include "symbols_list.h"

char *serialize_command(Row row);

char *serialize_operand(SymbolsList list, Row row, int operand_num);
char *set_immidiate(char binary[WORD_LENGTH], Operand op);
char *set_direct_offset(char binary[WORD_LENGTH], Operand op);
char *set_direct(char binary[WORD_LENGTH], Operand op, SymbolsList list);
char *set_direct_register(char binary[WORD_LENGTH], Operand op, bool is_dest);


char *  set_unused_bits(char binary[WORD_LENGTH]);
char *  set_opcode_bits(char binary[WORD_LENGTH], Row row);
char *  set_aer_bits(char binary[WORD_LENGTH],AER aer);
char * set_address_mode_bits(char binary[WORD_LENGTH],
		Operand operands[OPERANDS_MAX], int operand_index);
char * set_group_bits(char binary[WORD_LENGTH], Row row) ;

#endif


