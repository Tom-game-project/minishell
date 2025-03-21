#include "ast_checker.h"
#include "dict.h"
#include "list.h"
#include "parser.h"
#include "tom_parser.h"
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
#include <fcntl.h>

// for test 
#include <stdio.h>

//#include "../tests/tom_parser_tools/tools.h"
#include "test_tools.h"

int g_signal_number = 0;

/// 与えられた、shell cmdを解釈する関数
static t_ast *
parser_wrap(char *input)
{
    t_ast *ast;

    ast = NULL;
    if (e_result_paren_not_closed_err == tom_parser(input, &ast ))
    {
        //debug_dprintf(STDERR_FILENO, "minishell : not close syntax\n"); // TODO 書き換える
												    ft_putstr_fd("minishell : not close syntax\n", STDERR_FILENO);
		return (NULL);
    }
    else
    {
        debug_dprintf(STDERR_FILENO, "\ninput : %s\n\n", input);
    }
    return (ast);
}

void exec_ast(t_ast *ast, t_str_dict **env_dict, int *exit_status)
{
	t_syntax_result result;

	debug_dprintf(STDERR_FILENO, "ORIGIN PID (%d)\n", debug_getpid());
	if (ast == NULL)
	{
		*exit_status = 1;
		return ;
	}
	result = ast_checker(ast);
	print_checker_result(result);
	if (result == e_no_input)
	{
		debug_dprintf(STDERR_FILENO, "no_input\n");
		clear_ast(&ast);
	}
	else if (print_checker_result(result))
	{
		print_ast(ast, 0);
		*exit_status = exec(ast, env_dict);
		clear_ast(&ast);
	}
}

/// exit statuswを更新します
///
void exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status)
{
	t_ast *ast;

	//ast = parser_wrap(str);
	//if (ast == NULL)
	//{
	//	*exit_status = 1;
	//	return ;
	//}
	//result = ast_checker(ast);
	//print_checker_result(result);
	//if (result == e_no_input)
	//{
	//	debug_dprintf(STDERR_FILENO, "no_input\n");
	//	clear_ast(&ast);
	//}
	//else if (print_checker_result(result))
	//{
	//	print_ast(ast, 0);
	//	*exit_status = exec(ast, env_dict);
	//	clear_ast(&ast);
	//}
	ast = parser_wrap(str);
	exec_ast(ast, env_dict, exit_status);
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
t_loop_cntl device_loop_unit(char *input,int *exit_status, t_str_dict **env_dict)
{
	struct termios orig_termios;

	tcgetattr(STDIN_FILENO, &orig_termios);
	if (g_signal_number == SIGINT)
	{
		reconnect_stdin(exit_status);
		g_signal_number = 0;
		return (e_continue);
	}
	else if (input == NULL)
		return (e_break);
	else
		add_history(input);
	exec_shell_cmd(input, env_dict, exit_status);
	update_exit_status(*exit_status, env_dict);
	if (g_signal_number == SIGINT)
	{
		reconnect_stdin(exit_status);
		tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
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
		char *input;
		char *prompt_str;

		prompt_str = prompt(exit_status);
		input = readline(prompt_str);
		free(prompt_str);
		lctl = device_loop_unit(input, &exit_status, &env_dict);
		free(input);
		if (lctl == e_break)
			break;
		else if (lctl == e_continue)
			continue;
	}
	str_dict_clear(&env_dict, free, free);
	return (exit_status);
}

char *
none_device_readline()
{
	char c;
	t_char_list *lst;
	char *str;

	lst = NULL;
	while (1)
	{
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == 0)
			break ;
		char_list_push(&lst, c);
		if (c == '\0' || c == '\n')
			break ;
	}
	str = char_list_to_str(lst);
	char_list_clear(&lst);
	return (str);
}

/// stdin がデバイスでないとき
int none_device_main_loop(char *envp[])
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
		char *input;

		input = none_device_readline();
		if (ft_strlen(input) == 0)
			break;
		lctl = device_loop_unit(input, &exit_status, &env_dict);
		free(input);
		if (lctl == e_break)
			break;
		else if (lctl == e_continue)
			continue;
	}
	str_dict_clear(&env_dict, free, free);
	return (exit_status);
}
