#include "tom_parser_tools/tools.h"
#include "libft.h"
#include "parser.h"
#include "tom_parser.h"
#include <stdio.h>


/// ```bash
/// make test TEST_FILE=tests/tom_parser_test00.c
/// ```
int main(void)
{
    // char *input = ft_strdup("ls -la | grep src | head");
    // char *input = ft_strdup("ls -la | (ls -la | grep src)");
    // char *input = ft_strdup("cat < infile -e | grep 5");
    // char *input = ft_strdup("ls -la | cat < infile | grep 5");
    // 何故かsyntax errorとして処理されるケース
    // char *input = ft_strdup("< infile (cat)");
    // char *input = ft_strdup("ls -la | < infile (cat) | cat");
    //char *input = ft_strdup("< infile cat -e | grep 5");
    //char *input = ft_strdup("< infile cat | grep 5");
    char *input = ft_strdup("   && ls -la");
    t_ast *ast;

    ast = NULL;
    printf("test case \"%s\"\n", input);
    tom_parser(input,&ast);
    print_ast(ast, 0);
    free(input);
    return 0;
}
