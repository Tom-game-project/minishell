
#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include <stdlib.h>
#include "../tests/tom_parser_tools/tools.h"

//make vtest TEST_FILE=tests/kaara_parser_test/parser_test.c

void print(t_ast *ast, int i);


int main(void)
{
    char *input = ft_strdup("echo && ((ehllo >> infile) >> outfile) || $(hello | echo)");
    t_ast *ast;
    ast = NULL;
    parser(&ast, input);
    printf("\ninput : %s\n\n", input);
    print_ast(ast, 0);
    clear_ast(&ast);
    free(input);
    return 0;
}

//testcase

//((echo hello < infile) || ls -la) && grep .c
//< infile ls -la && grep .c || ((echo hello < infile) || ls -la) && grep .c