#include <stdio.h>
#include "second_scan.h"
#include "memory.h"
#include "rows_list.h"

void second_scan(Memory mem){



	/*concat the lists*/
	RowsList unified_list = concat_lists(mem->c_list,mem->d_list);

	/*update symbols address*/



}
