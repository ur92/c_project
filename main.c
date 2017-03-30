#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "def.h"
#include "file_reader.h"
#include "rows_list.h"
#include "parser.h"

int main(int argc, char **argv) {

    RowsList rl = read_file("./ps.as");



    return 0;
}
