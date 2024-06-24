/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:21:15 by kaara             #+#    #+#             */
/*   Updated: 2024/06/24 19:57:44 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
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