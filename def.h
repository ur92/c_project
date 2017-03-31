#define DEBUG 1
#define MEMORY_MAX 1000
#define LINE_MAX 80
#define SEGMENTS_MAX 3
#define COMMENT_CHAR ';'
#define LABEL_CHAR ':'
#define BASE_MEM_ADDRESS 100

char commands[16][5] = { "mov", "cmp", "add", "sub", "not", "clr", "lea", "inc",
		"dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop"};
