#include "tom_parser_tools/tools.h"
#include "libft.h"
#include "parser.h"
#include <stdio.h>


/// ```bash
/// make test TEST_FILE=tests/tom_parser_test00.c
/// ```
int main(void)
{
    //char *input = ft_strdup("ls -la | grep src | head");
    char *input = ft_strdup("ls -la | (ls -la | grep src)");
    t_ast *ast;

    ast = NULL;
    printf("test case \"%s\"\n", input);
    parser(&ast, input);
    print_ast(ast, 0);
    free(input);
    return 0;
}
