#include "parser.h"
#include "libft.h"
#include <stdbool.h>

bool    checker_str_ctl(char *str)
{
    while (*str != '\0') 
    {
        if (*str == '"')
            str += find_chr(str + 1, '"') + 2;
        else if (*str == '\'')
            str += find_chr(str + 1, '\'') + 2;
        else if (ft_strncmp(str, "$(", 2) == 0)
            str += find_chr(str + 1, ')') + 2;
        else if (*str == '(')
            str += find_chr(str + 1, ')') + 2;
        else if (ft_strncmp(str, "&&", 2) == 0)
            return (true);
        else if (ft_strncmp(str, "||", 2) == 0)
            return (true);
        str++;
    }
    return (false);
}

bool    checker_str_rdt(char *str)
{
    while (*str != '\0') 
    {
        if (*str == '"')
            str += find_chr(str + 1, '"') + 2;
        else if (*str == '\'')
            str += find_chr(str + 1, '\'') + 2;
        else if (ft_strncmp(str, "$(", 2) == 0)
            str += find_chr(str + 1, ')') + 2;
        else if (*str == '(')
            str += find_chr(str + 1, ')') + 2;
        else if (ft_strncmp(str, ">>", 2) == 0)
            return (true);
        else if (ft_strncmp(str, "<<", 2) == 0)
            return (true);
        else if (*str == '<')
            return (true);
        else if (*str == '>')
            return (true);
        else if (*str == '|')
            return (true);
        str++;
    }
    return (false);
}