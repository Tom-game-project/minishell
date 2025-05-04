/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_cd_too_many_arguments.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:36:08 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:36:08 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	report_cd_too_many_arguments(void)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
	return (1);
}
