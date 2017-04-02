#ifndef ROW_DEF_H
#define ROW_DEF_H

typedef enum rowState{
	IS_LABELED = 1<<0,
	IS_COMMAND = 1<<1,
	IS_DATA_COMMAND = 1<<2,
	IS_ENT_EXT_COMMAND = 1<<3
} RowState;


#endif

