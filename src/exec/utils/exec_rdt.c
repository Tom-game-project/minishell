/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:56:04 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:58:16 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "parser.h"
#include "exec.h"
#include "utils.h"
#include "expand_string.h"
#include "test_tools.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int	exec_rdt_proc(
	t_exec_args *args,
	void (*close_fd)(t_exec_args *),
	int (*open_func)(char *),
	int (*inner_exec)(t_exec_args *, int)
)
{
	char	*str;
	int		fd;

	close_fd(args);
	str = str_list_get_elem(args->ast->arg, 0);
	if (str == NULL)
	{
	}
	fd = open_func(str);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	inner_exec(args, fd);
	close(fd);
	return (0);
}

/// 文字列がシングルクォーテーション及び、
/// ダブルクォーテーションを含むかどうかを判定する関数
/// ```
/// 
/// ```
static bool	includes_quotation(char *str)
{
	while (*str != '\0')
	{
		if (
			*str == '"' || \
			*str == '\'')
			return (true);
		str++;
	}
	return (false);
}

/// 環境変数展開が必要なheredocについては、
/// 環境変数展開後の文字列を格納した隠しファイルのfdをリストに差し替えて
/// 他の関数は,展開関係なく普通にfdを読んでいるようになる
///
int	exec_rdt_proc_heredoc(
	t_exec_args *args,
	void (*close_fd)(t_exec_args *),
	int (*inner_exec)(t_exec_args *, int)
)
{
	int	fd;
	int	new_fd;

	close_fd(args);
	fd = int_list_pop(args->heredoc_fd_list, 0);
	if (!includes_quotation(str_list_get_elem(args->ast->arg, 0)))
	{
		new_fd = heredoc_expand_string_via_fd(fd, *args->envp_dict);
		debug_dprintf(STDERR_FILENO, \
			"close [%d] fd pid [%d]\n", fd, debug_getpid());
		close(fd);
		fd = new_fd;
	}
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	inner_exec(args, fd);
	debug_dprintf(STDERR_FILENO, "close [%d] fd pid [%d]\n", fd, debug_getpid());
	close(fd);
	return (0);
}
