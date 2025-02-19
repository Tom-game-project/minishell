# include "parser.h"

t_parse_result syntax_checker(char *input)
{
    int            tmp;
    int            idx;
    t_parse_result result;

    idx = 0;
    result = e_result_ok;
    while (*(input + idx) != '\0')
    {
        tmp = find_syntax(input + idx);
        if (tmp < 0)
        {
            result = e_result_paren_not_closed_err;
            return (result);
        }
        else if (tmp > 0)
            idx += tmp;
        else
            idx++;
    }
    return (result);
}