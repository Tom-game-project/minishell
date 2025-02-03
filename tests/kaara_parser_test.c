#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    t_ast   *ast;
    char    *input;

    ast = allocation_ast();
    input = ft_strdup("ls -la && true || false");
    ast = separate_and_store_control_operators(ast, &input);
    printf("%s", ast->cmd);
    printf("%s", ast->right_ast->cmd);
    printf("%s", ast->right_ast->right_ast->cmd);
    return (0);
}
