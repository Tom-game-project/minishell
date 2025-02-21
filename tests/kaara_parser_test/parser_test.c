
#include <stdio.h>
#include "ast_checker.h"
#include "libft.h"
#include "parser.h"
#include <stdlib.h>
#include "../tests/tom_parser_tools/tools.h"

//make vtest TEST_FILE=tests/kaara_parser_test/parser_test.c

int main(void)
{
    char *input = ft_strdup("< Makefile sleep 3 | echo '{' | wc -l");
    t_ast *ast;
    t_syntax_result result;
    ast = NULL;

    if (e_result_paren_not_closed_err == parser(&ast, input))
        printf("minishell : not close syntax\n");
    else
    {
        result = ast_checker(ast);
        if (print_checker_result(result) == true)
        {
            printf("\ninput : %s\n\n", input);
            print_ast(ast, 0);
        }
        clear_ast(&ast);
    }
    free(input);
    return 0;
}

//testcase

//((echo hello < infile) || ls -la) && grep .c
//< infile ls -la && grep .c || ((echo hello < infile) || ls -la) && grep .c