/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_too_long_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:36:22 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:37:44 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	report_too_long_input(void)
{
	ft_putstr_fd("minishell : too long input\n", STDERR_FILENO);
	return (1);
}
