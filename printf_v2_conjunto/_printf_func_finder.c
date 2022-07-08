#include "_printf.h"

ftype func_finder(char c)
{
    ftype func[] = {
        {'c', _putchar, 0},
        {'s', stringiterator, 0},
        {0, 0, 0}
    };
    int i = 0;

    while (func[i].op != 0)
    {
        if (func[i].fmt == c)
            return func[i];
        i++;
    }
    return func[i];
}