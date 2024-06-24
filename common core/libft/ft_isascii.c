/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:22:55 by kaara             #+#    #+#             */
/*   Updated: 2024/06/24 20:04:50 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
// 	int	c = 0;
//     c = 'a';
//     if (ft_isascii(c))
//     	printf ("ascii\n");
//     if (isascii(c))
//     	printf ("ascii\n");

// 	c = ' ';
//     if (ft_isascii(c))
//     	printf ("ascii\n");
//     if (isascii(c))
//     	printf ("ascii\n");

//     c = 160;
//     if (ft_isascii(c))
//     	printf ("ascii\n");
//     if (isascii(c))
//     	printf ("ascii\n");

// 	c = -1;
//     if (ft_isascii(c))
//     	printf ("no ascii\n");
//     if (isascii(c))
//     	printf ("no ascii\n");
// }