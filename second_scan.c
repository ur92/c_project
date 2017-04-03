#include <stdio.h>
#include "second_scan.h"
#include "memory.h"
#include "rows_list.h"
#include "symbols_list.h"
#include "helper.h"
#include "serialization.h"

void second_scan(Memory mem) {

	/*update symbols address*/
	update_data_symbols_address(mem->s_list, mem->ic);

	update_data_commands_address(mem->d_list, mem->ic);



	/*serialize command operands (label/entry/extern)*/
	serialize_command_operands(mem->c_list,mem->s_list);

}

void serialize_command_operands(RowsList list, SymbolsList s_list) {
	int i;
	Row row = list->head;
	while (row) {
		if (row->row_state & IS_COMMAND) {
			/*double DIRECT_REGISTER => serialize into one line*/
			if (row->length == row->number_of_operands) {
				row->operands[0]->binary = strdup(serialize_operand_one_row(row));
			} else {
				for (i = 0; i < row->number_of_operands; i++) {
					row->operands[i]->binary = strdup(serialize_operand(s_list, row, i));
				}
			}
		}
		row = row->next;
	}
}
