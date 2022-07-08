#include "_printf.h"

ftype func_finder(char c)
{
    ftype func[] = {
        {'c', _putchar, 0},
        {'%', _putchar, 0},
        {'s', stringiterator, 0},
        {'d', ntostring, 10},
        {'x', ntostring, 16},
        {'X', ntostring, 32},
        {'o', ntostring, 8},
        {'b', ntostring, 2},
        {'i', ntostring, 10},
        {'f', ftostring, 6},
        {'.', ftostring, 0},
        {0, 0, 0}
    };
    int i = 0;

    while (func[i].fmt != 0)
    {
        if (*(func[i].fmt) == c)
            return func[i];
        i++;
    }
    return func[i];
}