/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:48:38 by kaara             #+#    #+#             */
/*   Updated: 2024/08/14 18:45:12 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	print_c(int c);
void	print_s(char *str);
void	print_d_i(int di);
void	print_i(int i);
void	print_u(unsigned int u);
void	print_x(unsigned long x);
void	print_upper_x(unsigned long X);
void	print_p(void *ptr);
void	check_par(const char *format, va_list args);
int		ft_printf(const char *format, ...);
void	ft_putnbr_fd(int n, int fd);

#endif