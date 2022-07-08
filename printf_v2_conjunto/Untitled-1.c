#include <stdio.h>
#include "_printf.h"

int _printf(const char *format, ...)
{
    int i = 0, j = 0;
    ftype func_data;
    va_list ap;

    printf("Test1");
    va_start(ap, format);
        for (; format[i]; i++)
        {
            printf("%d", i);
        }
    va_end(ap);
    return (j);
}