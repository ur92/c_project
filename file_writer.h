#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <stdio.h>
#include <stdbool.h>
#include "memory.h"

bool write_ent_file(Memory mem, char *file_name);

bool write_ext_file(Memory mem, char *file_name);

bool write_ob_file(Memory mem, char *file_name);

FILE * create_file(char *file_name, char *ext);

#endif

