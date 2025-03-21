/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:32:16 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:32:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

/// この関数にstruct stat path_statを渡すと
/// シンボリックリンクだった場合なども考慮して設定される
int	set_stat(struct stat *path_stat, char *path)
{
	if (lstat(path, path_stat) != 0) 
	{
		perror("lstat");
		return (-1);
	}
	if (S_ISLNK(path_stat->st_mode))
	{
		if (stat(path, path_stat) != 0)
		{
			perror("stat");
			return (-1);
		}
	}
	return (0);
}

