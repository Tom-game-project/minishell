/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_cd_home_not_set.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:35:49 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:35:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	report_cd_home_not_set(void)
{
	ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
	return (1);
}
