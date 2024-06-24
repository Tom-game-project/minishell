/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:11:59 by kaara             #+#    #+#             */
/*   Updated: 2024/06/24 19:57:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9'));
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
// 	int c = 0;
//     c = 'a';
//     if (ft_isalnum(c))
//     	printf ("英字だよ\n");
//     if (isalnum(c))
//     	printf ("英字だよ\n");

// 	c = 'A';
//     if (ft_isalnum(c))
//     	printf ("英字だよ\n");
//     if (isalnum(c))
//     	printf ("英字だよ\n");

//     c = ' ';
//     if (ft_isalnum(c))
//     	printf ("英字じゃないよ\n");
//     if (isalnum(c))
//     	printf ("英字じゃないよ\n");

// 	c = '4';
//     if (ft_isalnum(c))
//     	printf ("数字だよ\n");
//     if (isalnum(c))
//     	printf ("数字だよ\n");

//     c = ')';
//     if (ft_isalnum(c))
//     	printf ("英字じゃないよ\n");
//     if (isalnum(c))
//     	printf ("英字じゃないよ\n");
// }