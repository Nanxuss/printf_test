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
            write(1, &s[i], 1);
    }

    va_end(ap);
    return (i + 1);
}