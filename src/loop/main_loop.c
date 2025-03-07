#include "ast_checker.h"
#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include "libft.h"
#include "envtools.h"
#include "sig.h"

#include <linux/limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <limits.h>
#include <unistd.h>
#include <termios.h>
// シグナル
#include <signal.h>

// for test 
#include <stdio.h>
#include "../tests/tom_parser_tools/tools.h"

int g_signal_number = 0;

#include <fcntl.h>

/// 与えられた、shell cmdを解釈する関数
static t_ast *
parser_wrap(char *input)
{
    t_ast *ast;

    ast = NULL;
    if (e_result_paren_not_closed_err == parser(&ast, input))
    {
        dprintf(STDERR_FILENO, "minishell : not close syntax\n");
		clear_ast(&ast);
		return (NULL);
    }
    else
    {
        dprintf(STDERR_FILENO, "\ninput : %s\n\n", input);
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
int exec_shell_cmd(char *str, t_str_dict **env_dict)
{
	t_ast *ast;
	int exit_status;
	t_syntax_result result;

	dprintf(STDERR_FILENO, "ORIGIN PID (%d)\n", getpid());
	ast = parser_wrap(str);

	if (ast == NULL)
		return (1);
	result = ast_checker(ast);
	print_checker_result(result);
	if (result == e_no_input)
	{
		clear_ast(&ast);
		return (1); // syntax error occured
	}
	else{
	exit_status = exec(ast, env_dict);
	//dprintf(STDERR_FILENO, "exit_status %d\n", exit_status);
	clear_ast(&ast);
	return (exit_status);
	}
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

typedef enum e_loop_cntl t_loop_cntl;
enum e_loop_cntl
{
	e_continue,
	e_break,
};

/// 一回のloop
t_loop_cntl loop_unit(int *exit_status, t_str_dict **env_dict)
{
	char *prompt_str;
	char *input;

	prompt_str = prompt(*exit_status);
	input = readline(prompt_str);
	free(prompt_str);
	if (g_signal_number == SIGINT)
	{
		free(input);
		reconnect_stdin(exit_status);
		g_signal_number = 0;
		return (e_continue);
	}
	else if (input == NULL)
		return (e_break);
	else
		add_history(input);
	*exit_status = exec_shell_cmd(input, env_dict);
	update_exit_status(*exit_status, env_dict);
	free(input);
	if (g_signal_number == SIGINT)
	{
		reconnect_stdin(exit_status);
		g_signal_number = 0;
	}
	return (e_continue);
}

int main_loop(char *envp[])
{
	t_str_dict *env_dict;
	int exit_status;
	t_loop_cntl lctl;

	sig_settig();
	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp); // 環境変数をセット
	exit_status = 0;
	str_dict_add(
                &env_dict,
                ft_strdup("?"),
                ft_itoa(exit_status),
                free
        );
	while (1)
	{
		lctl = loop_unit(&exit_status, &env_dict);
		if (lctl == e_break)
			break;
		else if (lctl == e_continue)
			continue;
	}
	str_dict_clear(&env_dict, free, free);
	return (0);
}

