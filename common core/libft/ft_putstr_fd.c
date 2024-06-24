/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:11:30 by kaara             #+#    #+#             */
/*   Updated: 2024/06/24 21:20:39 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write (fd, &(*s++), 1);
}

// int main(void)
// {
//     ft_putstr_fd("helloworld\n", 1);
//     ft_putstr_fd("error", 2);
// 	return (0);
// }