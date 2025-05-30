/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_nondup_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:28:39 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:29:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// 2 ^ 8 = 32
#define HIDE_NAME_LENGTH 8

static int	u32tostr(char *dst, unsigned int n)
{
	int	i;

	i = 0;
	while (i < HIDE_NAME_LENGTH)
	{
		dst[HIDE_NAME_LENGTH - i - 1] = "0123456789abcdef"[n % 0x10];
		n /= 0x10;
		i += 1;
	}
	return (0);
}

char	*gen_nondup_name(char *basename, t_str_list *dir_lisr)
{
	char			a[HIDE_NAME_LENGTH];
	unsigned int	i;
	char			*rstr;

	i = 0;
	while (i <= UINT_MAX)
	{
		u32tostr(a, i);
		rstr = ft_strjoin(basename, a);
		if (!str_list_in(rstr, dir_lisr))
			return (rstr);
		free(rstr);
		i += 1;
	}
	return (NULL);
}
