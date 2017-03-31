#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * str_dup(char *source){
    char * dest = malloc(sizeof(char) * strlen(source));
    strcpy(dest, source);

    return dest;
}

int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}
