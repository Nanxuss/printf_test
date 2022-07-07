#include "main.h"
#include <stdio.h>

/**
 * _printf: print string to stdout using variable arguments
 * @format: template string to print
 * 
 * Return: string length
 */

int _printf(const char *format, ...)
{
    int i = 0, j = 0, helper;
    ftype func_data;
    va_list ap;

    va_start(ap, format);
        while ((format != NULL) && (format[i] != '\0'))
        {
            if ((format[i] == 37) && (format[i + 1] != 37))
            {
                func_data = func_finder(format[i + 1]);
                switch (func_data.op)
                {
                    case 1:
                        j += stringiterator((va_arg(ap, char*)));
                        break;
                    case 2:
                        j += ntostring((va_arg(ap, int)), func_data.mod);
                        break;
                    case 3:
                        j += ftostring((va_arg(ap, double)), ((func_data.fmt == '.') ? (format[i + 2] - '0') : func_data.mod));
                        i = ((func_data.fmt == '.') ? i + 2 : i);
                        break;
                    case 4:
                        _putchar(va_arg(ap, int));
                        break;
                }
                i += 2;
            }
            else
            {
                _putchar(format[i++]);
                j++;
            }
        }
    va_end(ap);
    return (j);
}