
#include <stdio.h>
#include "ast_checker.h"
#include "libft.h"
#include "parser.h"
#include <stdlib.h>
#include "../tests/tom_parser_tools/tools.h"

//make vtest TEST_FILE=tests/kaara_parser_test/parser_test.c

int before_exec(t_ast   **ast, char *input)
{
    if (parser_wrap2(ast, input) == false)
    {
        printf("aaaa\n");
        return (2);
    }
    if (ast_checker_wrap2(ast) == false)
    {
        printf("aaaaqwqqq\n");
        return (2);
    }
    return (0);
}

int minishell(void)
{
    int exit_status;
    char *input = ft_strdup("< infile | echo hello");
    t_ast *ast;
    ast = NULL;

    exit_status = before_exec(&ast, input);
    if (exit_status == 2)
    {
        free(input);
        return (exit_status);
    }
    //exec
    print_ast(ast, 0);
    clear_ast(&ast);
    free(input);
    return (exit_status);
}

int main(void)
{
    t_syntax_result result;
    char *input = ft_strdup("< infile | echo hello");
    t_ast *ast;
    ast = NULL;

    parser(&ast, input);
    print_ast(ast, 0);
    result = ast_checker(ast);
    if (result == e_no_input)
        printf("aaaaaaaaa\n");
    clear_ast(&ast);
    free(input);
//    minishell();
    return (0);
}

//testcase

//((echo hello < infile) || ls -la) && grep .c
//< infile ls -la && grep .c || ((echo hello < infile) || ls -la) && grep .c
