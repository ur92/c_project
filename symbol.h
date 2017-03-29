typedef struct symbol{
    char *label;
    int address;
    struct symbol *next;
} *Symbol;