#ifndef ERROR_H
#define ERROR_H

#define INVALID_COMM "Invalid command or command not found"
#define INVALID_ADDRESSING_MODE "Cannot parse or invalid addressing mode"
#define FILE_ERROR "File error, cannot read file"
#define SYMBOL_ALREADY_EXIST "Symbol already exist and connot be redefined"


void print_error(char *error, int line_number);
#endif
