#include "parser.h"
#include "libft.h"
#include <stdbool.h>

bool    checker_str_ctl(char *str)
{
    int tmp;
    int idx;

    idx = 0;
    while (*(str + idx) != '\0')
    {
        if (ft_strncmp(str + idx, "&&", 2) == 0)
            return (true);
        else if (ft_strncmp(str + idx, "||", 2) == 0)
            return (true);
        tmp = find_syntax(str + idx);
        if (tmp > 0)
            idx += tmp;
        else
            idx++;
    }
    return (false);
}

bool    checker_str_pipe(char *str)
{
    int tmp;
    int idx;

    idx = 0;
    while (*(str + idx) != '\0')
    {
        if (*(str + idx) == '|')
            return (true);
        tmp = find_syntax(str + idx);
        if (tmp > 0)
            idx += tmp;
        else
            idx++;
    }
    return (false);
}

bool    checker_str_rdt(char *str)
{
    int tmp;
    int idx;

    idx = 0;
    while (*(str + idx) != '\0')
    {
        if (ft_strncmp(str + idx, ">>", 2) == 0)
            return (true);
        else if (ft_strncmp(str + idx, "<<", 2) == 0)
            return (true);
        else if (*(str + idx) == '<')
            return (true);
        else if (*(str + idx) == '>')
            return (true);
        else if (*(str + idx) == '|')
            return (true);
        tmp = find_syntax(str + idx);
        if (tmp > 0)
            idx += tmp;
        else
            idx++;
    }
    return (false);
}

int    str_ctl_len(char *str)
{
    int len;

    len = 0;
    while (*(str + len) != '\0') 
    {
        if (ft_strncmp((str + len), "&&", 2) == 0)
            return (len);
        else if (ft_strncmp((str + len), "||", 2) == 0)
            return (len);
        if (*(str + len) == '"')
            len += (find_syntax(str + len));
        else if (*(str + len) == '\'')
            len += find_syntax(str + len);
        else if (ft_strncmp((str + len), "$(", 2) == 0)
            len += find_syntax(str + len);
        else if (*(str + len) == '(')
            len += (find_syntax(str + len));
        else
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
        if (ft_strncmp((str + len), ">>", 2) == 0)
            return (len);
        else if (ft_strncmp((str + len), "<<", 2) == 0)
            return (len);
        else if (*(str + len) == '<')
            return (len);
        else if (*(str + len) == '>')
            return (len);
        else if (*(str + len) == '|')
            return (len);
        if (*(str + len) == '"')
            len += find_syntax(str + len);
        else if (*(str + len) == '\'')
            len += find_syntax(str + len);
        else if (ft_strncmp((str + len), "$(", 2) == 0)
            len += find_syntax(str + len);
        else if (*(str + len) == '(')
            len += find_syntax(str + len);
        else
            len++;
    }
    return (0);
}