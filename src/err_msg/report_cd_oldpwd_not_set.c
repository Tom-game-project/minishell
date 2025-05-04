/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_cd_oldpwd_not_set.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:36:04 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:36:05 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	report_cd_oldpwd_not_set(void)
{
	ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
	return (1);
}
