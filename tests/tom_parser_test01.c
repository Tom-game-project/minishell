#include "tom_parser_tools/tools.h"
#include "libft.h"
#include "parser.h"
#include <stdio.h>


/// ```bash
/// make test TEST_FILE=tests/tom_parser_test01.c
/// ```
int main(void)
{
    //char *input = ft_strdup("cat < infile | cat  < infile");
    //char *input = ft_strdup(" sleep 5 | << EOF cat");
    char *input = ft_strdup("false && << EOF");
    //char *input = ft_strdup("<< EOF | sleep 5");
    // char *input = ft_strdup("echo hello > /dev/stderr | echo world > /dev/stderr");
    //char *input = ft_strdup("grep hello << EOF1 << EOF2");
    
    t_ast *ast;

    ast = NULL;
    printf("test case \"%s\"\n", input);
    parser(&ast, input);
    print_ast(ast, 0);
    free(input);
    return 0;
}
