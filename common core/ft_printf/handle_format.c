/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:59:08 by kaara             #+#    #+#             */
/*   Updated: 2024/08/14 19:21:00 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(int c)
{
	write(1, &c, 1);
}

void	print_s(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_d_i(int di)
{
	ft_putnbr_fd(di, 1);
}

void	print_u(unsigned int u)
{
	int		i;
	char	result[10];

	i = 0;
	if (u == 0)
		write(1, "0", 1);
	while (u)
	{
		result[i++] = u % 10 + '0';
		u /= 10;
	}
	while (i > 0)
		write(1, &result[--i], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	un;
	char			result[12];

	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
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
		write(fd, &result[--i], 1);
}
