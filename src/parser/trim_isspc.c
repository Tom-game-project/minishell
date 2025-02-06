
#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

char *trim_isspc(char *str)
{
    int start;
    int end;

    if (str == NULL)
        return (NULL);
    start = 0;
    while (str[start] != '\0' && ft_isspace(str[start]))
        start++;
    end = ft_strlen(str);
    while (end > 0 && ft_isspace(str[end - 1]))
        end--;
    return (ft_substr(str, start, end - start));
}
