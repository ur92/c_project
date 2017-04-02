#ifndef HELPER_H
#define HELPER_H

int strcicmp(char const *a, char const *b);
char *strdup(const char *s);
char *strsep(char **stringp, const char *delim);

long int binary_to_int(char *binary);
char *int_to_binary(int a, char *buffer);

#endif
