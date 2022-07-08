#include "main.h"

int _printf(const char *format, ...)
{
    int i = 0, j = 0, helper;
    va_list ap;
    char *dummy;

    va_start(ap, format);
        while ((format) && (format[i] != '\0'))
        {
            if ((format[i] == 37) && (format[i] != 37))
            {
                switch (format[i + 1])
                {
                    case 'c':
                        j += _putchar(va_arg(ap, int));
                        break;
                    case 's':
                        j += stringiterator(va_arg(ap, char *));
                        break;
                    case 'd':
                        j += ntostring((va_arg(ap, int)), 10);
                        break;
                    case 'i':
                        j += ntostring((va_arg(ap, int)), 10);
                        break;
                    default:
                        break;
                }
                i += 2;
            }
            else
            {
                _putchar(format[i++]);
                j++;
                break;
            }
        }
    va_end(ap);
    return (j);
}