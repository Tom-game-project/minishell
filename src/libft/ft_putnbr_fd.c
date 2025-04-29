/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:32:23 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:01:07 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	un;
	char			result[11];

	i = 0;
	if (n == 0)
		write (fd, "0", 1);
	if (n < 0)
	{
		write (fd, "-", 1);
		un = (unsigned int)-n;
	}
	else
		un = (unsigned int)n;
	while (un)
	{
		result[i++] = un % 10 + '0';
		un /= 10;
	}
	while (i > 0)
		write (fd, &result[--i], 1);
}
