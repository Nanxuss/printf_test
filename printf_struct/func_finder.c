#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int func_finder(const char flag)
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