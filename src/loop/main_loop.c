#include "ast_checker.h"
#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include "libft.h"
#include "envtools.h"

#include <linux/limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <limits.h>
#include <unistd.h>

// for test 
#include <stdio.h>
#include "../tests/tom_parser_tools/tools.h"

/// 与えられた、shell cmdを解釈する関数
static t_ast *
parser_wrap(char *input)
{
    t_ast *ast;
    ast = NULL;
    if (e_result_paren_not_closed_err == parser(&ast, input))
    {
        dprintf(STDERR_FILENO, "minishell : not close syntax\n");
    }
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
exec_shell_cmd(char *str, t_str_dict **env_dict)
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
	//dprintf(STDERR_FILENO, "exit_status %d\n", exit_status);
	clear_ast(&ast);
	return (exit_status);
}

/// exit statusと、今いるディレクトリを表示するプロンプト
char *prompt(int exit_status)
{
	char buf[PATH_MAX];
	char *exit_str;
	t_char_list *rstr_list;
	char *rstr;

	exit_str = ft_itoa(exit_status);
	rstr_list = NULL;
	if (getcwd(buf, PATH_MAX) != NULL)
		char_list_push_str(&rstr_list, buf);
	char_list_push_str(&rstr_list, " [");
	char_list_push_str(&rstr_list, exit_str);
	char_list_push(&rstr_list, ']');
	char_list_push_str(&rstr_list, "> ");
	rstr = char_list_to_str(rstr_list);
	char_list_clear(&rstr_list);
	free(exit_str);
	return (rstr);
}

int
main_loop(char *envp[])
{
	t_str_dict *env_dict;
	char *input;
	int exit_status;

	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp);
	exit_status = 0;

	str_dict_add(
		&env_dict,
		ft_strdup("?"),
		ft_itoa(exit_status),
		free
	);
	while (1) {
		char *prompt_str;

		prompt_str = prompt(exit_status);
		input = readline(prompt_str);
		free(prompt_str);
		if (input == NULL)
			continue;
		if (*input)
			add_history(input);
		exit_status = exec_shell_cmd(input, &env_dict);
		update_exit_status(exit_status, &env_dict); // exit_statusを更新する
		free(input);
	}
	str_dict_clear(&env_dict, free, free);
	return (0);
}
