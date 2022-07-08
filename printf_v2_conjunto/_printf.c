#include "_printf.h"
#include <stdio.h>
#include <unistd.h>

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
        for (; format[i]; i++)
        {
            if (format[i] == '%')
			{
                func_data = func_finder(format[i + 1]);
			    if (func_data.op != 0)
                {
                    j += (*(func_data.op))(ap, func_data.mode);
			        i = ((func_data.fmt == '.') ? (i + 4) : (i + 2));
                }
            }
            else
                {
                    j += write(1, &format[i], 1);
                    i++;
                }
        }
    va_end(ap);
    return (j);
}