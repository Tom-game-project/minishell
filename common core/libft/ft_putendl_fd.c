/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:40:08 by kaara             #+#    #+#             */
/*   Updated: 2024/05/31 22:58:44 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write (fd, &(*s++), 1);
	write (fd, "\n", 1);
}

// int main(void)
// {
//     ft_putendl_fd("helloworld", 1);
//     ft_putendl_fd("error", 2);
// 	return (0);
// }