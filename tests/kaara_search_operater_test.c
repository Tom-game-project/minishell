#include <stdio.h>
#include "parser.h"
#include "libft.h"

int main(void)
{
    int     i;
    char *input;
    char *operater;

    i = 0;
    input = ft_strdup("ls -l | grep .c > results.txt | hello&&||");
    while (input != NULL)
    {
        operater = search_operater(&input);
        if (*operater != ' ')
        {
            printf("%d\n", i);
            printf("operater:%s\n", operater);
            printf("input:%s\n", input);
        }
        free(operater);
        i++;
    }
    free(input);
}
