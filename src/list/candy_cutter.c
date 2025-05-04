/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candy_cutter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:20:20 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/22 18:20:35 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

char	*candy_cutter(t_str_list **lst, int index)
{
	t_str_list	*t;
	char		*str;

	t = str_list_cut(lst, index);
	str = str_list_join(t, "");
	str_list_clear(&t, free);
	return (str);
}
