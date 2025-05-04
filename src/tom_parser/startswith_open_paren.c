/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startswith_open_paren.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:30:54 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 21:31:01 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	startswith_open_paren(char *str)
{
	return (ft_strncmp(str, "(", 1) == 0);
}
