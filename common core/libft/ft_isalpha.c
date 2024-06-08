/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:21:15 by kaara             #+#    #+#             */
/*   Updated: 2024/05/15 03:16:55 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (c);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
// 	int c = 0;
//     c = 'a';
//     if (ft_isalpha(c))
//     	printf ("英字だよ\n");
//     if (ft_isalpha(c))
//     	printf ("英字だよ\n");

// 	c = 'A';
//     if (ft_isalpha(c))
//     	printf ("英字だよ\n");
//     if (ft_isalpha(c))
//     	printf ("英字だよ\n");

//     c = ' ';
//     if (ft_isalpha(c))
//     	printf ("英字じゃないよ\n");
//     if (ft_isalpha(c))
//     	printf ("英字じゃないよ\n");

// 	c = '4';
//     if (ft_isalpha(c))
//     	printf ("英字じゃないよ\n");
//     if (ft_isalpha(c))
//     	printf ("英字じゃないよ\n");
// }