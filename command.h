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

typedef struct command {
	char name[COMMAND_MAX_LENGTH];
	int max_operands;
	AddressingMode possible_addressing_modes[OPERANDS_MAX];
} *Command;

Command commands[COMMANDS_COUNTER];

bool is_row_command(char *command_name);
Command create_command(int max_operands,
		AddressingMode possible_addressing_modes[OPERANDS_MAX], char *name);
Command get_command(char *command_name);
AddressingMode get_addressing_mode(char *operand);
int get_row_length(AddressingMode operands_am[OPERANDS_MAX]);
void init_commands();







/*
 char commands[COMMANDS_COUNTER][COMMAND_MAX_LENGTH] = { "mov", "cmp", "add",
 "sub", "not", "clr", "lea", "inc", "dec", "jmp", "bne", "red",
 "prn", "jsr", "rts", "stop" };
 */

#endif
