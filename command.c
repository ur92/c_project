#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "helper.h"
#include "def.h"

bool is_command(char *command_name) {
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

Command get_command(char *command_name) {
	int i;

	for (i = 0; i < COMMANDS_COUNTER; i++) {
		if (!striccmp(command_name, commands[i]->name))
			return commands[i];
	}
	return NULL;
}

