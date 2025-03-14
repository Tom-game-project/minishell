/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getppid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:50:49 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:51:12 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include <unistd.h>

int	debug_getppid(void)
{
	return (getppid());
}
#else

int	debug_getppid(void)
{
	return (0);
}
#endif
