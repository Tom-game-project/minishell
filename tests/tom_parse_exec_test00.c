#include "dict.h"
#include "exec.h"
#include "libft.h"
#include "parser.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "tom_parser_tools/tools.h"

t_ast *
parser_wrap(char *str)
{
    char *input = ft_strdup(str);
    t_ast *ast;
    ast = NULL;
    if (e_result_paren_not_closed_err == parser(&ast, input))
        printf("minishell : not close syntax\n");
    else
    {
        printf("\ninput : %s\n\n", input);
        print_ast(ast, 0);
    }
    free(input);
    return (ast);
}

/// parserとexecを合わせたテスト
///
/// ```bash
/// make test TEST_FILE=tests/tom_parse_exec_test00.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	t_str_dict *d;
	t_ast *ast;

	d = NULL;
	envp_to_str_dict(&d, envp);
	//ast = parser_wrap("< infile cat | grep 5");
	//ast = parser_wrap("ls -la | (ls -la | grep src)");
	//ast = parser_wrap("sleep 10 | true && echo hello");
	ast = parser_wrap("< minishell cat | xxd | tail");
	exec(ast, d);
        clear_ast(&ast);
	str_dict_clear(&d, free, free);
	return (0);
}
