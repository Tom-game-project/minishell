/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shadow_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:27:57 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:28:31 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "path.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef SHADOW_FILEPATH
# define SHADOW_FILEPATH "ms-"
#endif

#define TMP_PATH "./"

/// 隠しファイルを作りそのfdを返却する
int	create_shadow_file(int rw_fd[2])
{
	char		*pathname;
	t_str_list	*dlst;
	char		*fullpath;

	dlst = get_dir_list(TMP_PATH);
	pathname = gen_nondup_name(SHADOW_FILEPATH, dlst);
	fullpath = ft_strjoin(TMP_PATH, pathname);
	free(pathname);
	rw_fd[1] = open(fullpath, O_RDWR | O_CREAT, 0664);
	rw_fd[0] = open(fullpath, O_RDONLY, 0664);
	str_list_clear(&dlst, free);
	if (rw_fd[0] < 0 || rw_fd[1] < 0)
	{
		perror("minishell");
		return (-1);
	}
	if (unlink(fullpath) < 0)
	{
		perror("minishell: unlink");
		free(fullpath);
		close(rw_fd[0]);
		close(rw_fd[1]);
		return (-1);
	}
	free(fullpath);
	return (0);
}
