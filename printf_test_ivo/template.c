#include "main.h"

int (*func_finder)(const char flag)
{
    ffind selector[] = {
        {'d', ntostring},
        {'s', stringiterator},
    };
    int i;

	i = 0;
	while (selector[i].func != NULL)
	{
		if ((selector[i].func) == flag)
		{
			return (selector[i].func);
		}
		i++;
	}
	return (NULL);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int stringiterator(const char *s)
{
    int i;

    if (s)
    {
        for (i = 0; s[i]; i++)
            _putchar(s[i]);
    }

    return (strlen(s));
}

int ntostring(int n, int base)
{
    char *buffer;
    int i, len, lim, flag;

    i = 0;
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
                if ((n % base) >= 10)
                    buffer[i++] = ((n % base) + 55);
                else
                    buffer[i++] = ((n % base) + '0');
            n = n / base;
        }
        if (flag && (base == 10))
            buffer[i++] = 45;    
        i = ((base == 2) ? i : i - 1);
        for (; i >= 0; i--)
            _putchar(buffer[i]);
    }
    else
    {
        _putchar('0');
        return (1);
    }
    len = strlen(buffer);
    free(buffer);
    return (len);
}

int ftostring(double n, int precision)
{
    char *buffer;
    int i, ppoint, len, mov, apoint;

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
        for (; i >= 0; i--)
            _putchar(buffer[i]);
    }
    else
    {
        _putchar(48);
        _putchar(46);
        for (i = 0; i == precision; i++)
            _putchar(48);
        return (1);
    }
    len = strlen(buffer);
    free(buffer);
    return (len);
}

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
            if (format[i] == '%')
                func_finder(format[i + 1]);
            else
                _putchar(format[i + 1]);
        }
    _putchar(10);
    va_end(ap);

    return (j);
}