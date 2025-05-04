/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:24:39 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:44:20 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "list.h"
# include <sys/stat.h>
# include <stdbool.h>

t_str_list	*get_dir_list(char *name);

char		*get_full_path(char *cmd, char *env_path);

char		*gen_nondup_name(char *basename, t_str_list *dir_lisr);

int			create_shadow_file(int rw_fd[2]);

int			set_stat(struct stat *path_stat, char *path);

bool		is_dir(char *path);

#endif
