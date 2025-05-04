/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:50:11 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:50:40 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include <unistd.h>

int	debug_getpid(void)
{
	return (getpid());
}
#else

int	debug_getpid(void)
{
	return (0);
}
#endif
