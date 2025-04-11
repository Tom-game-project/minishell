/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_heredoc_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:08:25 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:08:45 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <unistd.h>

/// 数字のリストの中に含まれるfdをすべてcloseして、
/// リストの要素は削除します
int	close_all_heredoc_fd(t_int_list **node)
{
	t_anytype	rvalue;

	while (void_list_pop(node, 0, &rvalue) != -1)
	{
		close(rvalue.i32);
	}
	int_list_clear(node);
	return (0);
}
