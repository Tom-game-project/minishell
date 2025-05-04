/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:42:58 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:47:20 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVTOOLS_H
# define ENVTOOLS_H

# include "dict.h"
# include <stdbool.h>

char	*get_key_from_envp_ptr(char *str);

char	*get_value_from_envp_ptr(char *str);

bool	is_valid_env_char(char c);

bool	is_valid_identifier(char *str);

int		update_exit_status(\
	int exit_status, \
	t_str_dict **env_dict);

#endif
