/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:59:27 by kaara             #+#    #+#             */
/*   Updated: 2024/08/14 19:24:40 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_par(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				check_par(format, args);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

void	check_par(const char *format, va_list args)
{
	if (*format == 'c')
		print_c(va_arg(args, int));
	if (*format == 's')
		print_s(va_arg(args, char *));
	if (*format == 'p')
		print_p(va_arg(args, void *));
	if (*format == 'd' || *format == 'i')
		print_d_i(va_arg(args, int));
	if (*format == 'u')
		print_u(va_arg(args, unsigned int));
	if (*format == 'x')
		print_x(va_arg(args, unsigned long));
	if (*format == 'X')
		print_upper_x(va_arg(args, unsigned long));
	if (*format == '%')
		write(1, "%", 1);
}
