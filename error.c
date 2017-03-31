
#include <stdio.h>

#include "error.h"

void print_error(char *error, int line_number){
	fprintf( stderr, "Error on line %d: %s\n", line_number, error);
}
