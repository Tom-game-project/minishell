/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:09:39 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:09:45 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	includes_newline(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (true);
		str++;
	}
	return (false);
}

