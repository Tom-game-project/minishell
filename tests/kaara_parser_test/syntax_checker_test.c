# include "libft.h"
# include "parser.h"
# include <stdio.h>

int main(void)
{
    char *input = ft_strdup("hello (hello < world");
    int i = syntax_checker(input);
    printf("%d\n", i);
    free(input);
    return (0);
}