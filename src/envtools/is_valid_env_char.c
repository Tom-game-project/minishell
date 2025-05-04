/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_env_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:13:37 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:39:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

/// 
/// a-zA-Z0-9
/// 
bool	is_valid_env_char(char c)
{
	return (\
		ft_isalpha(c) || \
		ft_isdigit(c) || \
		'_' == c
	);
}
