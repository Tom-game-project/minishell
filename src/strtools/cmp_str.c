/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:39:50 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/04 15:39:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdbool.h>

bool	cmp_str(t_anytype a, t_anytype b)
{
	char	*a_str;
	char	*b_str;

	a_str = a.str;
	b_str = b.str;
	while (*a_str != '\0' && *b_str != '\0')
	{
		if (*a_str < *b_str)
		{
			return (true);
		}
		else if (*a_str > *b_str)
		{
			return (false);
		}
		a_str++;
		b_str++;
	}
	return (*a_str < *b_str);
}
