#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <stdio.h>
#include "row.h"

int serialize_command(Row row);

int serialize_data(Row row);


#endif


