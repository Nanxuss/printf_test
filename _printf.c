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
            switch (format[i])
            {
            case 37:
                switch (format[i + 1])
                {
                    case 'c':
                        _putchar(va_arg(ap, int));
                        j += 1;
                        i += 2;
                        break;

                    case 's':
                        j += stringiterator(va_arg(ap, char *));
                        i += 2;
                        break;

                    case 'd':
                        j += ntostring((va_arg(ap, int)), 10);
                        i += 2;
                        break;
                    
                    case 'x':
                        j += ntostring((va_arg(ap, int)), 16);
                        i += 2;
                        break;

                    case 'o':
                        j += ntostring((va_arg(ap, int)), 8);
                        i += 2;
                        break;

                    case 'b':
                        j += ntostring((va_arg(ap, int)), 2);
                        i += 2;
                        break;

                    case 'i':
                        j += ntostring((va_arg(ap, int)), 10);
                        i += 2;
                        break;

                    case '.':
                        j += ftostring((va_arg(ap, double)), (format[i + 2] - 48));
                        i += 4;
                        break;

                    case 'f':
                        j += ftostring((va_arg(ap, double)), 2);
                        i += 2;
                        break;

                    case 37:
                        _putchar('%');
                        i += 2;
                        j++;
                        break;
                    
                    default:
                        break;
                }
                break;

            case 92:
                
                break;
            
            default:
                _putchar(format[i]);
                i++;
                j++;
                break;
            }
        }
    _putchar(10);
    va_end(ap);

    return (j);
}