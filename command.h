#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "operand.h"

typedef enum commandName {
	MOV,
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

typedef struct command {
	char name[COMMAND_MAX_LENGTH];
	int max_operands;
	AddressingMode possible_addressing_modes[OPERANDS_MAX];
} *Command;


Command commands[COMMANDS_COUNTER];
/*commands[MOV]= create_command(2,[_123, _0123],"mov");*/
		/*{
		{ "mov", 2, { _123, _0123 } },
		{ "cmp", 2, { _0123, _0123 } },
		{ "add", 2, { _123, _0123 } },
		{ "sub", 2, { _123, _0123 } },
		{ "not", 1, { _123, 0 } },
		{ "clr", 1, { _123, 0 } },
		{ "lea", 2, { _123, _12 } },
		{ "inc", 1, { _123, 0 } },
		{ "dec", 1, { _123, 0 } },
		{ "jmp", 1, { _123, 0 } },
		{ "bne", 1, { _123, 0 } },
		{"red", 1, { _123, 0 } },
		{ "prn", 1, { _0123, 0 } },
		{ "jsr", 1, { _123,0 } },
		{ "rts", 0, { 0, 0 } },
		{ "stop", 0, { 0, 0 } } };*/

bool is_row_command(char *command_name);
Command create_command(int max_operands,
		AddressingMode possible_addressing_modes[OPERANDS_MAX], char *name);
Command get_command(char *command_name);
AddressingMode get_addressing_mode(char *operand);
int get_row_length(AddressingMode operands_am[OPERANDS_MAX]);

/*
 char commands[COMMANDS_COUNTER][COMMAND_MAX_LENGTH] = { "mov", "cmp", "add",
 "sub", "not", "clr", "lea", "inc", "dec", "jmp", "bne", "red",
 "prn", "jsr", "rts", "stop" };
 */

#endif
