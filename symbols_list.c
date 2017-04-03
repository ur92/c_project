#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "symbols_list.h"
#include "symbol.h"

SymbolsList init_symbols_list() {
	SymbolsList this = (SymbolsList) malloc(sizeof(struct symbolsList));
	this->head = this->current = NULL;
	return this;
}

Symbol insert_symbol(SymbolsList list, Symbol prev, Symbol new_symbol) {
	Symbol prev_decleration;

	if (!is_exist(list, new_symbol->label)) {
		/*if the list is empty*/
		if (list->head == NULL) {
			list->head = list->current = new_symbol;
		} else {
			/*insert the new symbol*/
			Symbol tmp = prev->next;
			prev->next = new_symbol;
			new_symbol->next = tmp;
		}
		/*update the current*/
		if (list->current->next != NULL) {
			list->current = list->current->next;
		}
		return new_symbol;
	} else {
		prev_decleration = symbol_search(list, new_symbol->label);
		if (prev_decleration->is_entry) {
			/*if the previous decloration was entry, merge the symbols*/
			prev_decleration->address = new_symbol->address;
			prev_decleration->is_command = new_symbol->is_command;
		} else {
			return NULL;
		}
	}
	return new_symbol;
}

Symbol push_symbol(SymbolsList list, Symbol new_symbol) {
	return insert_symbol(list, list->current, new_symbol);
}

bool is_exist(SymbolsList list, char *label) {
	if (symbol_search(list, label))
		return true;
	else
		return false;
}

Symbol symbol_search(SymbolsList list, char *label) {
	Symbol this = list->head;
	while (this) {
		if (!strcmp(this->label, label)) {
			return this;
		} else {
			this = this->next;
		}
	}
	return NULL;
}

int get_symbol_address(char *value, SymbolsList list){
	Symbol s = symbol_search(list, value);
	if(s){
		return s->address;
	}
	else
		return 0;
}

void update_data_symbols_address(SymbolsList list, int ic) {
	Symbol this = list->head;
	while (this) {
		if (!this->is_command && !this->is_external) {
			this->address += ic;
		}
		this = this->next;
	}
}
