/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect_i_proc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:58:27 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 19:01:12 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "exec.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// infileでの基本的な動作

/// もし読み込み側にすでにfdが設定されていたら、閉じる
///
static void	close_fd(t_exec_args *args)
{
	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd);
}

/// 読み込み専用でファイルを開く
static int	open_func(char *path)
{
	return (open(path, O_RDONLY, 0644));
}

/// 再帰的な関数呼び出し
static int	inner_exec(t_exec_args *args, int input_fd)
{
	if (args->ast->right_ast != NULL)
	{
		return (exec2(&(t_exec_args){\
			args->ast->right_ast, \
			args->envp_dict, \
			args->heredoc_fd_list, \
			input_fd, \
			args->output_fd, \
			-1}));
	}
	else if (args->ast->left_ast != NULL)
	{
		return (exec2(&(t_exec_args){\
			args->ast->left_ast, \
			args->envp_dict, \
			args->heredoc_fd_list, \
			input_fd, \
			args->output_fd, \
			-1}));
	}
	return (1);
}

int	exec_redirect_i_proc(t_exec_args *args)
{
	return (
		exec_rdt_proc(
			args,
			close_fd,
			open_func,
			inner_exec
		)
	);
}
