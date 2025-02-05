
#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include <stdlib.h>

//make vtest TEST_FILE=tests/kaara_parser_test.c

int main (void)
{
    t_ast   *ast;
    char    *input;

    ast = NULL;
    input = ft_strdup("ls -la && true || false");
    ast = parser(input);
    // if (ast->cmd != NULL)
        printf("%s\n", ast->cmd);
    // if (ast->cmd != NULL)   
        printf("%s\n", ast->right_ast->cmd);
    free(ast->cmd);
    return (0);
}
