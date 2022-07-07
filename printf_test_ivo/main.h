#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#ifndef MAIN
#define MAIN

typedef struct function_type {
    char fmt;
    int op;
    int mod;
} ftype;

int _printf(const char *format, ...);
int _putchar(char c);
int stringiterator(const char *s);
int ntostring(int n, int base);
int ftostring(double n, int precision);
ftype func_finder(char c);

#endif
