#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#ifndef PRNTF
#define PRNTF

typedef struct function_type {
    char fmt;
    int (*op)(va_list ap, int mode);
    int mode;
} ftype;

int _printf(const char *format, ...);
int _putchar(va_list args, int mode);
int stringiterator(va_list args, int mode);
int ntostring(va_list args, int mode);
int ftostring(va_list args, int mode);
int singlewrite(char c);
ftype func_finder(char c);

#endif