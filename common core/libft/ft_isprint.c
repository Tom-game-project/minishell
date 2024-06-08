/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:51:50 by kaara             #+#    #+#             */
/*   Updated: 2024/05/15 02:32:08 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (c);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
// 	int	c = 0;
//     c = 'a';
//     if (ft_isprint(c))
//     	printf ("ascii1\n");
//     if (isprint(c))
//     	printf ("ascii2\n");

// 	c = ' ';
//     if (ft_isprint(c))
//     	printf ("ascii3\n");
//     if (isprint(c))
//     	printf ("ascii4\n");

//     c = 300;
//     if (ft_isprint(c))
//     	printf ("no ascii5\n");
//     if (isprint(c))
//     	printf ("no ascii6\n");

// 	c = -1;
//     if (ft_isprint(c))
//     	printf ("no ascii\n");
//     if (isprint(c))
//     	printf ("no ascii\n");
// }