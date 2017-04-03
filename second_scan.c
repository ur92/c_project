#include <stdio.h>
#include "second_scan.h"
#include "memory.h"
#include "rows_list.h"
#include "symbols_list.h"
#include "helper.h"
#include "serialization.h"

void second_scan(Memory mem) {

	RowsList unified_list;

	/*update symbols address*/
	update_data_symbols_address(mem->s_list, mem->ic);

	update_data_commands_address(mem->d_list, mem->ic);
	/*concat the lists*/
	unified_list = concat_lists(mem->c_list, mem->d_list);

	/*serialize command operands (label/entry/extern)*/
	serialize_command_operands(unified_list, mem->s_list);

}

void serialize_command_operands(RowsList list, SymbolsList s_list) {
	int i;
	Row row = list->head;
	while (row) {
		if (row->row_state & IS_COMMAND) {
			/*double DIRECT_REGISTER => serialize into one line*/
			if (row->length == row->number_of_operands
					&& !(row->row_state & IS_DATA_COMMAND)) {
				row->operands[0]->binary = strdup(
						serialize_operand_one_row(row));
			} else {
				for (i = 0; i < row->number_of_operands; i++) {
					row->operands[i]->binary = strdup(
							serialize_operand(s_list, row, i));
				}
			}
		} else if (row->row_state & IS_DATA_COMMAND
				&& row->command == d_commands[DATA]) {
			for (i = 0; i < row->number_of_operands; i++) {
				row->operands[i]->binary = strdup(
						serialize_operand(s_list, row, i));
			}
		}
		row = row->next;
	}
}
