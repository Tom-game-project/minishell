/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:11:59 by kaara             #+#    #+#             */
/*   Updated: 2024/05/15 03:16:41 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (c);
	else if ('0' <= c && c <= '9')
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