/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:49:46 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/01 19:41:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "expand_string.h"
#include "libft.h"
#include "list.h"
#include "parser.h"
#include "strtools.h"
#include "test_tools.h"
#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static bool	is_junk(t_anytype elem)
{
	return (ft_streq(elem.str, ""));
}

static char	*get_open_file_name_from_list(t_exec_args *exec_args)
{
	t_str_list	*args;
	t_str_list	*junk;
	char		*str;
	int			args_length;

	args = expand_env_vars(exec_args->ast->arg, *exec_args->envp_dict);
	junk = void_list_filter(&args, is_junk);
	str_list_clear(&junk, free);
	args_length = str_list_len(args);
	if (args_length != 1)
	{
		if (args_length == 0)
			ft_putstr_fd("minishell: File not set for redirect\n",
				STDERR_FILENO);
		else
			ft_putstr_fd("minishell: Multiple file are set\n", STDERR_FILENO);
		str_list_clear(&args, free);
		return (NULL);
	}
	str = ft_strdup(str_list_get_elem(args, 0));
	str_list_clear(&args, free);
	return (str);
}

int	exec_rdt_proc(t_exec_args *exec_args, void (*close_fd)(t_exec_args *),
		int (*open_func)(char *), int (*inner_exec)(t_exec_args *, int))
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

/// ```
///
/// ```
static bool	includes_quotation(char *str)
{
	while (*str != '\0')
	{
		if (*str == '"' || *str == '\'')
			return (true);
		str++;
	}
	return (false);
}

///
int	exec_rdt_proc_heredoc(t_exec_args *args, void (*close_fd)(t_exec_args *),
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
		debug_dprintf(STDERR_FILENO, "close [%d] fd pid [%d]\n", fd,
			debug_getpid());
		close(fd);
		fd = new_fd;
	}
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	exit_status = inner_exec(args, fd);
	debug_dprintf(STDERR_FILENO, "close [%d] fd pid [%d]\n", fd,
		debug_getpid());
	close(fd);
	return (exit_status);
}
