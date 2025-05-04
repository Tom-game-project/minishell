/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ope_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:36:20 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:36:25 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "strtools.h"

bool	is_ope_string(char *str)
{
	return (
		ft_streq(str, "||") || \
		ft_streq(str, "&&")
	);
}
