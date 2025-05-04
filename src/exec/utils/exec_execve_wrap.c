/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execve_wrap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:11 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:48:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "exec.h"
#include "list.h"
#include "parser.h"
#include "path.h"
#include "libft.h"
#include "sig.h"
#include "test_tools.h"
#include "err_msg.h"

#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/// 
void	check_executable_file(char *path)
{
	struct stat	f_stat;

	set_stat(&f_stat, path);
	if (S_ISREG(f_stat.st_mode))
	{
		return ;
	}
	else if (S_ISDIR(f_stat.st_mode))
	{
		report_is_a_directory(path);
		exit(126);
	}
	else
	{
		report_no_such_file_or_directory(path);
		exit(126);
	}
}

int	execve_wrap(t_exec_args *args)
{
	char		*fullpath;
	char		*cmd;
	char		**argv;
	char		**envp;
	t_str_dict	*env_path_node;

	set_sigint_default();
	cmd = ft_strdup(str_list_get_elem(args->ast->arg, 0));
	argv = str_list_to_array(args->ast->arg);
	env_path_node = get_str_dict_by_key(*args->envp_dict, "PATH");
	if (env_path_node == NULL)
		report_command_not_found(cmd);
	fullpath = get_full_path(cmd, env_path_node->value);
	if (fullpath == NULL)
		report_command_not_found(cmd);
	if (access(fullpath, X_OK) == -1)
		report_permission_denied(cmd);
	check_executable_file(fullpath);
	envp = str_dict_to_envp(*args->envp_dict);
	debug_dprintf(STDERR_FILENO, "cmd %s running on pid(%d).ppid(%d)\n", \
			fullpath, debug_getpid(), debug_getppid());
	execve(fullpath, argv, envp);
	return (1);
}

int	execve_wrap2(t_str_list *args, t_str_dict *envp_dict)
{
	char		*fullpath;
	char		*cmd;
	char		**argv;
	char		**envp;
	t_str_dict	*env_path_node;

	set_sigint_default();
	if (str_list_len(args) < 1)
		exit(0);
	cmd = ft_strdup(str_list_get_elem(args, 0));
	argv = str_list_to_array(args);
	env_path_node = get_str_dict_by_key(envp_dict, "PATH");
	if (env_path_node == NULL)
		report_command_not_found(cmd);
	fullpath = get_full_path(cmd, env_path_node->value);
	if (fullpath == NULL)
		report_command_not_found(cmd);
	if (access(fullpath, X_OK) == -1)
		report_permission_denied(cmd);
	check_executable_file(fullpath);
	envp = str_dict_to_envp(envp_dict);
	debug_dprintf(STDERR_FILENO, "cmd %s running on pid(%d).ppid(%d)\n", \
			fullpath, debug_getpid(), debug_getppid());
	execve(fullpath, argv, envp);
	return (1);
}
