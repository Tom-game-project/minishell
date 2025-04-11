#ifndef LOOP_PRIVATE_H
#define LOOP_PRIVATE_H

#include "parser.h"
#include "dict.h"

char	*prompt(int exit_status);

/// 入力されたコマンドが文法的に正しいかどうかをチェックする関数
void	exec_ast(t_ast *ast, t_str_dict **env_dict, int *exit_status);

void	exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status);

#endif
