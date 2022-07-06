#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAIN
#define MAIN

typedef struct func_finder 
{
    const char func;
    int (*operation);
} ffind;

int _printf(const char *format, ...);
int _putchar(char c);
int stringiterator(const char *s);
int ntostring(int n, int base);
int ftostring(double n, int precision);
int func_finder(const char flag);

#endif
