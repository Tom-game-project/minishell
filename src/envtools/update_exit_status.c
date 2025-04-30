/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:59:50 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:00:04 by tmuranak         ###   ########.fr       */
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
/// 更新されただけの場合str_tmpはfreeして良い
int	update_exit_status(int exit_status, t_str_dict **env_dict)
{
	char	*str_tmp;

	str_tmp = ft_strdup("?");
	if (str_dict_add(env_dict, str_tmp, ft_itoa(exit_status), free) == 0)
		free(str_tmp);
	return (0);
}
