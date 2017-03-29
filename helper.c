#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * str_dup(char *source){
    char * dest = malloc(sizeof(char) * strlen(source));
    strcpy(dest, source);

    return dest;
}