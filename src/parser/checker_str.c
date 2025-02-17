#include "parser.h"
#include "libft.h"
#include <stdbool.h>

bool    checker_str_ctl(char *str)
{
    while (*str != '\0') 
    {
        if (*str == '"')
            str += find_syntax(str) - 1;
        else if (*str == '\'')
            str += find_syntax(str) - 1;
        else if (ft_strncmp(str, "$(", 2) == 0)
            str += find_syntax(str) - 1;
        else if (*str == '(')
            str += find_syntax(str) - 1;
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
            str += find_syntax(str) - 1;
        else if (*str == '\'')
            str += find_syntax(str) - 1;
        else if (ft_strncmp(str, "$(", 2) == 0)
            str += find_syntax(str) - 1;
        else if (*str == '(')
            str += find_syntax(str) - 1;
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

int    str_ctl_len(char *str)
{
    int len;

    len = 0;
    while (*(str + len) != '\0') 
    {
        if (*(str + len) == '"')
            len += find_syntax(str + len) - 1;
        else if (*(str + len) == '\'')
            len += find_syntax(str + len) - 1;
        else if (ft_strncmp((str + len), "$(", 2) == 0)
            len += find_syntax(str + len) - 1;
        else if (*(str + len) == '(')
            len += find_syntax(str + len) - 1;
        else if (ft_strncmp((str + len), "&&", 2) == 0)
            return (len);
        else if (ft_strncmp((str + len), "||", 2) == 0)
            return (len);
        len++;
    }
    return (0);
}

int    str_rdt_len(char *str)
{
    int len;

    len = 0;
    while (*(str + len) != '\0') 
    {
        if (*(str + len) == '"')
            len += find_syntax(str + len) - 1;
        else if (*(str + len) == '\'')
            len += find_syntax(str + len) - 1;
        else if (ft_strncmp((str + len), "$(", 2) == 0)
            len += find_syntax(str + len) - 1;
        else if (*(str + len) == '(')
            len += find_syntax(str + len) - 1;
        else if (ft_strncmp((str + len), ">>", 2) == 0)
            return (len);
        else if (ft_strncmp((str + len), "<<", 2) == 0)
            return (len);
        else if (*(str + len) == '<')
            return (len);
        else if (*(str + len) == '>')
            return (len);
        else if (*(str + len) == '|')
            return (len);
        len++;
    }
    return (0);
}