#include "parser.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char    *input;
    input = ft_strdup("echo && hello");
    printf("%s : & : %ld\n", input, find_chr(input + 1, '&'));
    free(input);
    return (0);
}

//インデックスを返す