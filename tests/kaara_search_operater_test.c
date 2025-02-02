#include <stdio.h>
#include "parser.h"
#include "libft.h"

int main(void)
{
    char *input;
    char *operater;

    input = ft_strdup("(sleep 3 | echo echo hello");
    operater = search_operater(&input);
    printf("%s\n", operater);
    printf("%s\n", input);
    free(input);
    free(operater);
}

