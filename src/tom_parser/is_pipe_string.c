/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:10:20 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/01 19:33:20 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "strtools.h"

bool	is_pipe_string(char *str)
{
	return (
		ft_streq(str, "|")
	);
}
