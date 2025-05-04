/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:37:25 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:37:25 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include <stdbool.h>
#include <sys/stat.h>

bool	is_dir(char *path)
{
	struct stat	path_stat;

	set_stat(&path_stat, path);
	return (S_ISDIR(path_stat.st_mode));
}
