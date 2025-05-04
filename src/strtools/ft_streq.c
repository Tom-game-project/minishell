/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:09:20 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:09:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

//bool ft_streq(char *a, char *b)
//{
//	return (
//		ft_strncmp(a, b, ft_strlen(a)) == 0 && 
//		ft_strncmp(b, a, ft_strlen(b)) == 0
//	);
//}

/// `"hello" == "world"` -> false
/// `"hello" == "hello"` -> true
bool	ft_streq(char *a, char *b)
{
	if (ft_strlen(a) == ft_strlen(b))
	{
		while (*a != '\0')
		{
			if (*a != *b)
				return (false);
			a++;
			b++;
		}
		return (true);
	}
	else
		return (false);
}
