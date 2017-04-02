#include <stdio.h>
#include "row.h"
#include "row_def.h"



int serialize_command(Row row){

}

int serialize_data(Row row){
	if(row->command == d_commands[DATA]){

	}else if(row->command == d_commands[STRING]){

	}
}
