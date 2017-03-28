typedef struct row *Row;
enum addressingMode {IMMIDIATE, DIRECT, DIRECT_OFFSET,  DIRECT_REGISTER};

Row create_row(
        int address, 
        bool is_label, 
        bool absolute,
        bool relative,
        bool external,
        enum addressingMode op1_add,
        char *op1_value,
        enum addressingMode op2_add,
        char *op2_value,
        char *command,
        char *label,
        int binary
        );
