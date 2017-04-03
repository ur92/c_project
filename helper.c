#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "def.h"

char *strdup(const char *s) {
	char *d = malloc(strlen(s) + 1);
	if (d == NULL)
		return NULL;
	strcpy(d, s);
	return d;
}

char * strsep(char **stringp, const char *delim) {
	char *s;
	const char *spanp;
	int c, sc;
	char *tok;

	if ((s = *stringp) == NULL)
		return (NULL);
	for (tok = s;;) {
		c = *s++;
		spanp = delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				*stringp = s;
				return (tok);
			}
		} while (sc != 0);
	}
}

int strcicmp(char const *a, char const *b) {
	for (;; a++, b++) {
		int d = tolower(*a) - tolower(*b);
		if (d != 0 || !*a)
			return d;
	}
}

long int binary_to_int(char *binary) {
	return strtol(binary, NULL, 2);
}

char *int_to_binary(int a, char *buffer) {
	int i;
	buffer += (INT_BUF_SIZE - 2);

	for (i = INT_BUF_SIZE - 2; i >= 0; i--) {
		*buffer-- = (a & 1) + '0';

		a >>= 1;
	}

	return buffer;
}

void reverse(char s[WORD_LENGTH])
{
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

