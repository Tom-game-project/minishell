#include "dict.h"
#include "parser.h"
#include "exec.h"

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// for test 
#include <stdio.h>

static t_ast *
parser_wrap(char *input)
{
    t_ast *ast;
    ast = NULL;
    if (e_result_paren_not_closed_err == parser(&ast, input))
        printf("minishell : not close syntax\n");
    else
    {
        printf("\ninput : %s\n\n", input);
        // print_ast(ast, 0); // ast を表示する
    }
    return (ast);
}

// 返り値はexit status
int
exec_shell_cmd(char *str, t_str_dict *env_dict)
{
	t_ast *ast;
	int exit_status;

	ast = parser_wrap(str);
	exit_status = exec(ast, env_dict);
        clear_ast(&ast);
	return (exit_status);
}

int
main_loop(char *envp[])
{
	t_str_dict *env_dict;
	char *input;

	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp);
	while (1) {
		input = readline("minishell> ");
		if (input == NULL)
			continue;
		if (*input) {  // 入力が空でない場合
			add_history(input);  // 入力を履歴に追加
		}
		exec_shell_cmd(input, env_dict);
		free(input);
	}
	return (0);
}
