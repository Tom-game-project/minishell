#include "list.h"
#include "dict.h"
#include "exec.h"
#include "libft.h"
#include "parser.h"

#include <stdio.h>
#include <unistd.h>
#include "tom_parser_tools/tools.h"


static t_ast *
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
int main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	t_str_dict *d;
	t_ast *ast;

	d = NULL;
	envp_to_str_dict(&d, envp);
	ast = parser_wrap("< infile cat | grep Tom");
	exec(ast, d, STDIN_FILENO);
        clear_ast(&ast);
	return (0);
}
