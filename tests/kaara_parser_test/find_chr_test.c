#include "parser.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char    *input;
    input = ft_strdup("$(echo && (hello world))");
    
    printf("%s : & : %d\n", input, find_syntax(input));
    free(input);
    return (0);
}

//インデックスを返す