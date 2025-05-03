/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_from_envp_ptr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:11:44 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:40:40 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// 文字列から、環境変数のidentifierを見つける
char	*get_key_from_envp_ptr(char *str)
{
	unsigned int	l;
	char			*str_tmp;

	l = 0;
	str_tmp = str;
	while (*str != '=')
	{
		if (*str == '\0')
			break ;
		l++;
		str++;
	}
	return (ft_substr(str_tmp, 0, l));
}
