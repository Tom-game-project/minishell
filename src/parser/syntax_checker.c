# include "parser.h"
#include <stdbool.h>

bool syntax_checker(char *input)
{
    int            tmp;
    int            idx;

    idx = 0;
    while (*(input + idx) != '\0')
    {
        if (*(input + idx) == ')')
            return (false);
        tmp = find_syntax(input + idx);
        if (tmp < 0)
            return (false);
        else if (tmp > 0)
            idx += tmp;
        else
            idx++;
    }
    return (true);
}