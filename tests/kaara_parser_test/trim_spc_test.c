#include "parser.h"
#include "libft.h"
#include <stdio.h>

int main(void)    
{
    char *head_element;

    head_element = ft_strtrim("    hello world ", " ");
    printf("---%s---\n", head_element);
    free(head_element);
    return (0);
}

//ft_strtrimは最初と最後から切り出す