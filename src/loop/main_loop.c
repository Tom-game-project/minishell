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
#include <termios.h>
// シグナル
#include <signal.h>

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
int exec_shell_cmd(char *str, t_str_dict **env_dict)
{
	t_ast *ast;
	int exit_status;

	dprintf(STDERR_FILENO, "ORIGIN PID (%d)\n", getpid());
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

/// グローバル変数
int g_signal_number = 0;

/// back slashに限らないシグナルの受信
void handle_sigquit(int sig) {
	(void) sig;
	g_signal_number = sig;
}

void disable_ctrl_backslash() 
{
	struct termios orig_termios;
	struct termios new_termios;

	tcgetattr(STDIN_FILENO, &orig_termios); // 現在の端末設定を取得
	new_termios = orig_termios;
	new_termios.c_cc[VQUIT] = _POSIX_VDISABLE; // `Ctrl-\` を無効化
	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

int main_loop(char *envp[])
{
	t_str_dict *env_dict;
	char *input;
	int exit_status;
	//struct sigaction sa_sigint;
	struct sigaction sa_sigquit;

	///シグナルハンドラの設定
	// Ctrl-\ (SIGQUIT) のための sigaction を設定
	sa_sigquit.sa_handler = handle_sigquit;
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigquit.sa_flags = 0;
	sigaction(SIGQUIT, &sa_sigquit, NULL);

	/// `Ctrl-\`が標準出力されてしまうのを防ぐ
	disable_ctrl_backslash();

	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp);
	exit_status = 0;
	while (1)
	{
		char *prompt_str;

		prompt_str = prompt(exit_status);
		input = readline(prompt_str);
		free(prompt_str);
		if (input == NULL)
			break; // EOFが送られたら終了
		if (*input)
			add_history(input);
		exit_status = exec_shell_cmd(input, &env_dict);
		update_exit_status(exit_status, &env_dict); // exit_statusを更新する
		free(input);
	}
	str_dict_clear(&env_dict, free, free);
	return (0);
}
