/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:14:13 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:14:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"
#include <stdlib.h>

/// `$?` exit status を更新する
///
///
/// TODO 急いで修正が必要
///
///
int	update_exit_status(int exit_status, t_str_dict **env_dict)
{
	char	*str_tmp;

	str_tmp = ft_strdup("?");
	if (str_dict_add(env_dict, str_tmp, ft_itoa(exit_status), free))
	{
	}
	else
		free(str_tmp);
	return (0);
}
