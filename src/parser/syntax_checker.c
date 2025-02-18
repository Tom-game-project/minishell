#include "parser.h"

int syntax_checker(char *input)
{
    int tmp;
    int start;

    start = 0;
    while (*input + start == '\0')
    {
        tmp = find_syntax(input + start);
        if (tmp < 0)
            return (-1);
        else if (tmp == 0)
            start++;
        start += tmp; 
    }
    return (0);
}
