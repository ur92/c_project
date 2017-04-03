#include <stdio.h>
#include "rows_list.h"
#include "def.h"
#include "error.h"

#include "rows_list.h"
#include "file_writer.h"
#include "memory.h"
#include "helper.h"

bool write_ent_file(Memory mem, char *file_name) {
	FILE * fp;
	Symbol s;

	fp = create_file(file_name, ".ent");
	s= mem->s_list->head;
	while (s) {
		if (s->is_entry) {
			fprintf(fp, "%s %04X\r\n", s->label, s->address);
		}
		s = s->next;
	}

	fclose(fp);
	return true;
}

bool write_ext_file(Memory mem, char *file_name) {
	FILE * fp;
	Symbol s;

	fp = create_file(file_name, ".ext");
	s= mem->es_list->head;
	while (s) {
		fprintf(fp, "%s %04X\r\n", s->label, s->address);
		s = s->next;
	}

	fclose(fp);

	return true;
}

bool write_ob_file(Memory mem, char *file_name) {
	FILE * fp;
	int i, code;
	RowsList unified_list;
	Row row;
	fp = create_file(file_name, ".ob");

	/*concat the lists*/
	unified_list = concat_lists(mem->c_list, mem->d_list);

	fprintf(fp, "%X %04X\r\n", mem->ic, mem->dc);

	row = unified_list->head;
	while (row) {
		if (row->row_state & IS_COMMAND) {
			code = binary_to_int(row->binary);
			fprintf(fp, "%X %04X\r\n", row->address, code);

			for (i = 0; i < row->length - 1; i++) {
				code = binary_to_int(row->operands[i]->binary);
				fprintf(fp, "%X %04X\r\n", row->address + 1 + i, code);
			}
		} else if (row->row_state & IS_DATA_COMMAND) {
			if (row->command == d_commands[DATA]) {
				for (i = 0; i < row->length; i++) {

					code = binary_to_int(row->operands[i]->binary);
					fprintf(fp, "%X %04X\r\n", row->address + i, code);
				}
			} else if (row->command == d_commands[STRING]) {
				for (i = 0; i < row->length; i++) {
					code = row->operands[0]->value[i];
					fprintf(fp, "%X %04X\r\n", row->address + i, code);
				}
			}
		}

		row = row->next;
	}

	fclose(fp);
	return true;
}

FILE * create_file(char *file_name, char *ext) {
	char path[LINE_MAX];
	strcpy(path, file_name);
	strcat(path, ext);

	return fopen(path, "ab+");
}

