/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_envp_ptr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:13:11 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:39:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*get_value_from_envp_ptr(char *str)
{
	unsigned int	s;
	char			*str_tmp;

	s = 0;
	str_tmp = str;
	while (*str != '=')
	{
		if (*str == '\0')
			return (NULL);
		s++;
		str++;
	}
	return (ft_substr(str_tmp, s + 1, ft_strlen(str_tmp) - s - 1));
}
