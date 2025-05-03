#ifndef LOOP_PRIVATE_H
#define LOOP_PRIVATE_H

#include "parser.h"
#include "dict.h"
#include "ast_checker.h"

/// exit statusと、今いるディレクトリを表示するプロンプト
typedef enum e_loop_cntl	t_loop_cntl;
enum e_loop_cntl
{
	e_through,
	e_continue,
	e_break,
};

char	*prompt(int exit_status);

/// 入力されたコマンドが文法的に正しいかどうかをチェックする関数
int	exec_ast(t_ast *ast, t_str_dict **env_dict, t_syntax_result	result);

int	exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status);

t_loop_cntl	loop_unit(\
	char *input, int *exit_status, t_str_dict **env_dict, bool *newline_flag);

t_loop_cntl	device_once_loop(int *exit_status, bool *newline_flag, t_str_dict **env_dict);

t_loop_cntl
none_device_once_loop(int *exit_status, bool *newline_flag, t_str_dict **env_dict);
#endif
