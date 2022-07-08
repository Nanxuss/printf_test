#include "_printf.h"
#include <unistd.h>

int _putchar(va_list ap, int mode)
{
    char *c = va_arg(ap, char *);
    
    (void) mode;
    write(1, &c, 1);
    va_end(ap);
	return (1);
}

int singlewrite(char c)
{
    return write(1, &c, 1);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

int stringiterator(va_list ap, int mode)
{
    char *s = va_arg(ap, char *);;
    
    (void) mode;
    write(1, s, _strlen(s));
    va_end(ap);
    return (_strlen(s));
}

int ntostring(va_list ap, int base)
{
    char *buffer;
    int n;
    int i = 0, len, flag;

    n = (va_arg(ap, int));
    buffer = malloc(64);
    flag = ((n < 0) ? 1 : 0);
    n = ((n < 0) ? (n * -1) : n);
    if (n != 0)
    {
        while (n > 0)
        {
            if (base <= 10)
                buffer[i++] = ((n % base) + '0');
            else if (base == 16)
            {
                if ((n % base) >= 10)
                    buffer[i++] = ((n % base) + ((base == 32) ? 55 : 87));
                else
                    buffer[i++] = ((n % base) + '0');
            }
            n = n / base;
        }
        if (flag && (base == 10))
            buffer[i++] = 45;    
        i = ((base == 2) ? i : i - 1);
        for (; i >= 0; i--)
            write(1, &buffer[i], 1);
    }
    else
    {
        buffer[i++] = '0';
        write(1, &buffer[i], 1);
        return (1);
    }
    len = _strlen(buffer);
    free(buffer);
    va_end(ap);
    return (len);
}