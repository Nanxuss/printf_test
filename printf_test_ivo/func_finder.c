#include "main.h"

ftype func_finder(char c)
{
    ftype func[] = {
        {'s', 1},
        {'d', 2, 10},
        {'x', 2, 16},
        {'X', 2, 32},
        {'o', 2, 8},
        {'b', 2, 2},
        {'i', 2, 10},
        {'f', 3, 6},
        {'.', 3},
        {'c', 4},
        {0, 0, 0}
    };
    int i = 0;

    while ((func[i].fmt != c) && func[i].fmt)
        i++;
    return func[i];
}