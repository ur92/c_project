#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "operand.h"

typedef enum commandName {
	MOV=0,
	CMP,
	ADD,
	SUB,
	NOT,
	CLR,
	LEA,
	INC,
	DEC,
	JMP,
	BNE,
	RED,
	PRN,
	JSR,
	RTS,
	STOP
} commandName;

typedef enum dataCommandName {
	DATA=0,
	STRING,
	ENTRY,
	EXTERN
} DataCommandName;

typedef struct command {
	char name[COMMAND_MAX_LENGTH];
	int max_operands;
	AddressingMode possible_addressing_modes[OPERANDS_MAX];
} *Command;

Command i_commands[I_COMMANDS_COUNTER];
Command d_commands[D_COMMANDS_COUNTER];

bool is_row_command(char *command_name);
Command create_command(int max_operands,
		AddressingMode possible_addressing_modes[OPERANDS_MAX], char *name);
Command get_i_command(char *command_name);
Command get_d_command(char *command_name);
void init_commands();

#endif
