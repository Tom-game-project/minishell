/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:13:53 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:14:02 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envtools.h"
#include "stdbool.h"

bool	is_valid_identifier(char *str)
{
	while (*str != '\0')
	{
		if (!is_valid_env_char(*str))
			return (false);
		str++;
	}
	return (true);
}
