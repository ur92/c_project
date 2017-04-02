#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <stdio.h>
#include "row.h"

char * serialize_command(Row row);

char * serialize_data(Row row);

void set_unused_bits(char binary[WORD_LENGTH]);
void set_opcode_bits(char binary[WORD_LENGTH], Row row);
void set_aer_bits(char binary[WORD_LENGTH],AER aer);


#endif


