#include "_printf.h"
#include <stdio.h>

/**
 * _printf: print string to stdout using variable arguments
 * @format: template string to print
 * 
 * Return: string length
 */

int _printf(const char *format, ...)
{
    int i = 0, j = 0;
    ftype func_data;
    va_list ap;

    printf("Test1");
    va_start(ap, format);
        while ((format != NULL) && (format[i] != '\0'))
        {
			func_data = func_finder(format[i + 1]);
			j += (*(func_data.op))(ap, func_data.mode);
			i = ((func_data.fmt == '.') ? (i + 4) : (i + 2));
        }
    va_end(ap);
    return (j);
}