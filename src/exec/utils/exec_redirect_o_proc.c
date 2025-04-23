/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect_o_proc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:01:22 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 20:53:46 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


/// もし書き込み側にすでにfdが設定されていたら、閉じる
static void	close_fd(t_exec_args *args)
{
	if (args->output_fd != STDOUT_FILENO)
		close(args->output_fd);
}

/// 書き込み専用でファイルを開く
static int	open_func(char *path)
{
	return (open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

/// 再帰的な関数呼び出し
static int	inner_exec(t_exec_args *args, int output_fd)
{
	if (args->ast->right_ast != NULL)
	{
		return (exec2(&(t_exec_args){\
			args->ast->right_ast, \
			args->envp_dict, \
			args->heredoc_fd_list, \
			args->input_fd, \
			output_fd, \
			-1}));
	}
	else if (args->ast->left_ast != NULL)
	{
		return (exec2(&(t_exec_args){\
			args->ast->left_ast, \
			args->envp_dict, \
			args->heredoc_fd_list, \
			args->input_fd, \
			output_fd, \
			-1}));
	}
	return (1);
}

int	exec_redirect_o_proc(t_exec_args *args)
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

