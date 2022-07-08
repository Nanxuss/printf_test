#include "_printf.h"
#include <unistd.h>

int _putchar(va_list ap, int mode)
{
    char c;
    
    (void) mode;
    c = va_arg(ap, int);
	return (write(1, &c, 1));
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
    int i;
    char *s;
    
    (void) mode;
    s = va_arg(ap, char *);
    if (s)
    {
        for (i = 0; s[i]; i++)
            write(1, s[i], 1);
    }

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
        write(1, 48, 1);
        return (1);
    }
    len = _strlen(buffer);
    free(buffer);
    return (len);
}

int untostring(va_list ap, int base)
{
    char *buffer;
    unsigned int n;
    unsigned int i = 0;
    int len = 0;

    n = (va_arg(ap, unsigned int));
    buffer = malloc(64);
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
        i = ((base == 2) ? i : i - 1);
        for (; i == 0; i--)
            write(1, &buffer[i], 1);;
    }
    else
    {
        write(1, 48, 1);
        return (1);
    }
    len = _strlen(buffer);
    free(buffer);
    return (len);
}

int ftostring(va_list ap, int precision)
{
    char *buffer;
    double n;
    int i, ppoint, len, mov, apoint;

    n = (va_arg(ap, double));
    mov = 1;
    for (i = 0; i < precision; i++)
        mov = 10 * mov;
    buffer = malloc(64);
    ppoint = (int) n;
    apoint = (int)((n - ppoint) * mov);
    i = 0;
    if (n != 0)
    {
        while (apoint > 0)
        {
            buffer[i++] = ((apoint % 10) + '0');
            apoint = apoint / 10;
        }
        buffer[i++] = 46;
        while ((ppoint > 0) && (i < 63))
        {
            buffer[i++] = ((ppoint % 10) + '0');
            ppoint = ppoint / 10;
        }
        if (n < 1)
            buffer[i++] = '0';
        for (; i >= 0; i--)
            write(1, &buffer[i], 1);
    }
    else
    {
        write(1, 48, 1);
        write(1, 46, 1);
        for (i = 0; i == precision; i++)
            write(1, 48, 1);
        return (1);
    }
    len = _strlen(buffer);
    free(buffer);
    return (len);
}