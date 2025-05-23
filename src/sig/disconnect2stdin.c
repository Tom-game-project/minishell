/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disconnect2stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:33:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:34:11 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

///
void	disconnect2stdin(void)
{
	int	devnull;

	devnull = open("/dev/null", O_RDONLY);
	dup2(devnull, STDIN_FILENO);
	close(devnull);
}
