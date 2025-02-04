
#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include <stdlib.h>

//make vtest TEST_FILE=tests/kaara_parser_test.c

int main (void)
{
    t_ast   *ast;
    char    *input;

    ast = allocation_ast();
    input = ft_strdup("ls -la && true || false");
    ast = parser(input);
    exit(0);
    printf("%s\n", ast->cmd);
    // printf("%s\n", ast->right_ast->cmd);
    // printf("%s\n", ast->right_ast->right_ast->cmd);
    free(ast->cmd);
    // free(ast->right_ast->cmd);
    // free(ast->right_ast->right_ast->cmd);
    return (0);
}
