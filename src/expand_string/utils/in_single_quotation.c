/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_single_quotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:08:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:53:42 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "private.h"

t_anchor	anchor_q_proc(char c, t_list_args *group_args)
{
	if (c == '\'')
	{
		push_str_group2(group_args, e_word);
		return (e_anchor_out);
	}
	else
		char_list_push(group_args->str_group, c);
	return (e_anchor_q);
}
