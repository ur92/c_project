#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "helper.h"
#include "def.h"

int is_row_command(char *command_name) {
	return (get_i_command(command_name) == NULL) ? 0 : IS_COMMAND;
}

int is_row_data_command(char *command_name) {
	Command comm = get_d_command(command_name);
	bool is_data_comm;
	is_data_comm = ( comm== d_commands[DATA] || comm== d_commands[STRING]);
	return is_data_comm?IS_DATA_COMMAND:0;
}


int is_ent_ext_command(char *command_name) {
	Command comm = get_d_command(command_name);
	bool is_ent_ext;
	is_ent_ext = ( comm== d_commands[EXTERN]|| comm== d_commands[ENTRY]);
	return is_ent_ext?IS_ENT_EXT_COMMAND:0;
}

Command create_command(int max_operands,
		AddressingMode possible_addressing_modes[OPERANDS_MAX], char *name) {
	Command this = malloc(sizeof(struct command));
	int i;

	if (this) {
		this->max_operands = max_operands;
		for (i = 0; i < OPERANDS_MAX; i++) {
			this->possible_addressing_modes[i] = possible_addressing_modes[i];
		}
		strcpy(this->name, name);
	}
	return this;
}

void init_commands() {
	AddressingMode addresing_modes_pairs[][OPERANDS_MAX] =
	{
			{_123, _0123 },
			{ _0123, _0123 },
			{ _123, 0 },
			{ _0123, 0 },
			{ _123,_12 },
			{ 0, 0 }
	};
	i_commands[MOV] = create_command(2, addresing_modes_pairs[0], "mov");
	i_commands[CMP] = create_command(2, addresing_modes_pairs[1], "cmp");
	i_commands[ADD] = create_command(2, addresing_modes_pairs[0], "add");
	i_commands[SUB] = create_command(2, addresing_modes_pairs[0], "sub");
	i_commands[NOT] = create_command(2, addresing_modes_pairs[2], "not");
	i_commands[CLR] = create_command(2, addresing_modes_pairs[2], "clr");
	i_commands[LEA] = create_command(2, addresing_modes_pairs[4], "lea");
	i_commands[INC] = create_command(2, addresing_modes_pairs[2], "inc");
	i_commands[DEC] = create_command(2, addresing_modes_pairs[2], "dec");
	i_commands[JMP] = create_command(2, addresing_modes_pairs[2], "jmp");
	i_commands[BNE] = create_command(2, addresing_modes_pairs[2], "bne");
	i_commands[RED] = create_command(2, addresing_modes_pairs[2], "red");
	i_commands[PRN] = create_command(2, addresing_modes_pairs[3], "prn");
	i_commands[JSR] = create_command(2, addresing_modes_pairs[2], "jsr");
	i_commands[RTS] = create_command(2, addresing_modes_pairs[5], "rts");
	i_commands[STOP] = create_command(2, addresing_modes_pairs[5], "stop");

	d_commands[DATA] = create_command(0, addresing_modes_pairs[5], ".data");
	d_commands[STRING] = create_command(0, addresing_modes_pairs[5], ".string");
	d_commands[ENTRY] = create_command(0, addresing_modes_pairs[5], ".entry");
	d_commands[EXTERN] = create_command(0, addresing_modes_pairs[5], ".extern");
}


Command get_i_command(char *command_name) {
	int i;

	for (i = 0; i < I_COMMANDS_COUNTER; i++) {
		if (!strcicmp(command_name, i_commands[i]->name))
			return i_commands[i];
	}
	return NULL;
}

Command get_d_command(char *command_name) {
	int i;

	for (i = 0; i < D_COMMANDS_COUNTER; i++) {
		if (!strcicmp(command_name, d_commands[i]->name))
			return d_commands[i];
	}
	return NULL;
}

Command get_command(RowState state, char *command_name){
	if(state&IS_COMMAND){
		return get_i_command(command_name);
	}
	else{
		return get_d_command(command_name);
	}
}


