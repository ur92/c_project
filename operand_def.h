#ifndef OPERNAD_DEF_H
#define OPERNAD_DEF_H

#include "def.h"

#define _12 DIRECT&DIRECT_OFFSET
#define _123 _12&DIRECT_REGISTER
#define _0123 IMMIDIATE&_123

typedef enum aer {
	ABSOLUTE = 0, EXTERNAL = 1, RELATIVE = 2
} AER;

typedef enum addressingMode {
	NO_ADDRESS = 0,
	IMMIDIATE = 1 << 0,
	DIRECT = 1 << 1,
	DIRECT_OFFSET = 1 << 2,
	DIRECT_REGISTER = 1 << 3
} AddressingMode;

typedef struct operand {
	AddressingMode address_mode;
	AER aer;
	char *value;
	char *binary;
}* Operand;

#endif
