#include "parser.h"
#include "libft.h"
#include <stdbool.h>

static int update_idx(char *str, int len);

bool    checker_str_ctl(char *str)
{
    int idx;

    idx = 0;
    while (*(str + idx) != '\0')
    {
        if (ft_strncmp(str + idx, "&&", 2) == 0)
            return (true);
        else if (ft_strncmp(str + idx, "||", 2) == 0)
            return (true);
        idx = update_idx(str + idx, idx);
    }
    return (false);
}

bool    checker_str_pipe(char *str)
{
    int idx;

    idx = 0;
    while (*(str + idx) != '\0')
    {
        if (*(str + idx) == '|')
            return (true);
        idx = update_idx(str + idx, idx);
    }
    return (false);
}

bool    checker_str_rdt(char *str)
{
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
        idx = update_idx(str + idx, idx);
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
        len = update_idx(str + len, len);
    }
    return (0);
}

int    str_pipe_len(char *str)
{
    int len;

    len = 0;
    while (*(str + len) != '\0') 
    {
        if (*(str + len) == '|')
            return (len);
        len = update_idx(str + len, len);
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
        len = update_idx(str + len, len);
    }
    return (0);
}

static int update_idx(char *str, int len)
{
    int tmp;

    tmp = find_syntax(str);
    if (tmp == 0)
        len++;
    else
        len += tmp;
    return (len);
}