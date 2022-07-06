#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int i, j, helper;
    va_list ap;
    char *dummy; 

    i = 0;
    j = 0;
    va_start(ap, format);
        while ((format != NULL) && (format[i] != '\0'))
        {
            if ((format[i] == '%') && (format[i + 1] != '\0'))
                func_finder(format[i + 1]);
            else
                _putchar(format[i + 1]);
        }
    _putchar(10);
    va_end(ap);

    return (j);
}