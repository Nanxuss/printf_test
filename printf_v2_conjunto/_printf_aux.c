#include "_printf.h"
#include <unistd.h>

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