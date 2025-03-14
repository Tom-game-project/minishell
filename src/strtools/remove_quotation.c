/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:09:50 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:10:21 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// 領域をピッタリは確保しない
/// " 'を取り除いた新しい領域を確保する
char	*remove_quotations(char *str)
{
	char	*new_str;
	char	*tmp;

	new_str = ft_strdup(str);
	tmp = new_str;
	while (*str != '\0')
	{
		if (*str == '"' || *str == '\'')
		{
		}
		else
		{
			*new_str = *str;
			new_str++;
		}
		str++;
	}
	*new_str = '\0';
	return (tmp);
}

