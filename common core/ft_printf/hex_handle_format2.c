/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handle_format2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:09:13 by kaara             #+#    #+#             */
/*   Updated: 2024/08/14 18:25:29 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(unsigned long x)
{
	int		i;
	char	*hex_digits;
	char	result[21];

	i = 0;
	hex_digits = "0123456789abcdef";
	if (x == 0)
		write(1, "0", 1);
	while (x)
	{
		result[i++] = hex_digits[x % 16];
		x = x / 16;
	}
	result[i] = '\0';
	while (i)
		write (1, &result[--i], 1);
}

void	print_upper_x(unsigned long X)
{
	int		i;
	char	*hex_digits;
	char	result[21];

	i = 0;
	hex_digits = "0123456789abcdef";
	if (X == 0)
		write(1, "0", 1);
	while (X)
	{
		result[i++] = hex_digits[X % 16];
		X = X / 16;
	}
	result[i] = '\0';
	while (i)
		write(1, &result[--i], 1);
}

void	print_p(void *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	write(2, "0X", 2);
	print_x(addr);
}
