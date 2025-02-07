/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chiled_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:47:32 by kaara             #+#    #+#             */
/*   Updated: 2025/01/29 10:47:32 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

#include <stdio.h>

void chiled_process(t_ast *ast, t_pipex	*pipex, char *envp[])
{
	setup_filefd(pipex, cmdc_i);
	pipex->execve_argv
		= store_execve_argv(pipex, pipex->cmdv[cmdc_i]);
	execve(pipex->full_path, pipex->execve_argv, envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}
