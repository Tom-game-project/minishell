#include "ast_checker.h"
#include "dict.h"
#include "parser.h"
#include "exec.h"

#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

// for test 
#include <stdio.h>
#include <unistd.h>
#include "../tests/tom_parser_tools/tools.h"

static t_ast *
parser_wrap(char *input)
{
    t_ast *ast;
    ast = NULL;
    if (e_result_paren_not_closed_err == parser(&ast, input))
        dprintf(STDERR_FILENO, "minishell : not close syntax\n");
    else
    {
        dprintf(STDERR_FILENO, "\ninput : %s\n\n", input);
        // print_ast(ast, 0); // ast を表示する
    }
    return (ast);
}

/// 与えられたastに文法上のエラーが存在しないことを確かめる関数
/// - true
/// 実行可能
/// - false
/// 実行しない（引数が不正）
bool	ast_checker_wrap(t_ast	*ast)
{
	t_syntax_result	result;

	result = ast_checker(ast);
	if (print_checker_result(result))
	{
		print_ast(ast, 0);
		return (true);
	}
	else
	{
		// 実行が続行できないとき
		return (false);
	}
}

// 返り値はexit status
int
exec_shell_cmd(char *str, t_str_dict *env_dict)
{
	t_ast *ast;
	int exit_status;

	ast = parser_wrap(str);
	if (!ast_checker_wrap(ast))
	{
	    clear_ast(&ast);
		return (1); // syntax error occured
	}
	exit_status = exec(ast, env_dict);
	dprintf(STDERR_FILENO, "exit_status %d\n", exit_status);
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
