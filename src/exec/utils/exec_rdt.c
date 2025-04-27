/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:49:46 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 20:53:00 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
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

#include "strtools.h"

static bool is_junk(t_anytype elem)
{
	return (ft_streq(elem.str, ""));
}

/// もし引数に過不足があればエラー出力をする
static char *get_open_file_name_from_list(
	t_exec_args *exec_args
)
{
	t_str_list	*args;
	t_str_list *junk;
	char	*str;

	args = expand_env_vars(exec_args->ast->arg, *exec_args->envp_dict);
	junk = void_list_filter(&args, is_junk);
	str_list_clear(&junk, free);
	if (str_list_len(args) != 1)
	{
		ft_putstr_fd("minishell: Multiple redirects are set\n", STDERR_FILENO);
		str_list_clear(&args, free);
		return (NULL);
	}
	str = ft_strdup(str_list_get_elem(args, 0)); // ここで環境変数を展開
	str_list_clear(&args, free);
	return (str);
}

int	exec_rdt_proc(
	t_exec_args *exec_args,
	void (*close_fd)(t_exec_args *),
	int (*open_func)(char *),
	int (*inner_exec)(t_exec_args *, int)
)
{
	char	*str;
	int		fd;
	int		exit_status;

	close_fd(exec_args);
	str = get_open_file_name_from_list(exec_args);
	if (str == NULL)
		return (1);
	fd = open_func(str);
	if (fd == -1)
	{
		free(str);
		perror("minishell");
		return (1);
	}
	exit_status = inner_exec(exec_args, fd);
	free(str);
	close(fd);
	return (exit_status);
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
	int (*inner_exec)(t_exec_args *, int))
{
	int	fd;
	int	new_fd;
	int	exit_status;

	close_fd(args);
	fd = int_list_pop(args->heredoc_fd_list, 0);
	if (!includes_quotation(str_list_get_elem(args->ast->arg, 0)))
	{
		new_fd = heredoc_expand_string_via_fd(fd, *args->envp_dict);
		debug_dprintf(STDERR_FILENO, "close [%d] fd pid [%d]\n",
			fd, debug_getpid());
		close(fd);
		fd = new_fd;
	}
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	exit_status = inner_exec(args, fd);
	debug_dprintf(STDERR_FILENO, "close [%d] fd pid [%d]\n",
		fd, debug_getpid());
	close(fd);
	return (exit_status);
}
