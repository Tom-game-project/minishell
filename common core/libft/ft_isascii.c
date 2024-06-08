/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:22:55 by kaara             #+#    #+#             */
/*   Updated: 2024/05/20 10:13:27 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
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