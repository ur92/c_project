#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "helper.h"
#include "def.h"

bool is_row_command(char *command_name) {
	return (get_command(command_name) == NULL) ? false : true;
}

Command create_command(int max_operands,
		AddressingMode possible_addressing_modes[OPERANDS_MAX], char *name) {
	Command this = (Command) malloc(sizeof(struct command));
	int i;

	if (this) {
		this->max_operands = max_operands;
		for(i=0;i<OPERANDS_MAX;i++){
			this->possible_addressing_modes[i] = possible_addressing_modes[i];
		}
		strcpy(this->name, name);
	}
	return this;
}

void init_commands(){
	AddressingMode pam[OPERANDS_MAX] = { _123, _0123 };
	/*commands[MOV]= create_command(2,pam,"mov");*/
	commands[MOV]= { "mov", 2, { _123, _0123 } };
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
}

Command get_command(char *command_name) {
	int i;

	for (i = 0; i < COMMANDS_COUNTER; i++) {
		if (!strcicmp(command_name, commands[i]->name))
			return commands[i];
	}
	return NULL;
}

