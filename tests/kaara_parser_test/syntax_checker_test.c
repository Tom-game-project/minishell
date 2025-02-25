# include "libft.h"
# include "parser.h"
# include <stdio.h>

//make vtest TEST_FILE=tests/kaara_parser_test/syntax_checker_test.c

int main(void)
{
    char *input = ft_strdup("\"hello < world\"");
    int i = syntax_checker(input);
    printf("%d\n", i);
    free(input);
    return (0);
}