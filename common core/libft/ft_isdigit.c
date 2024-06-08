/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:38:26 by kaara             #+#    #+#             */
/*   Updated: 2024/05/15 03:17:01 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
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
//     if (ft_isdigit(c))
//     	printf ("数字じゃないよ\n");
//     if (isdigit(c))
//     	printf ("数字じゃないよ\n");

// 	c = 'A';
//     if (ft_isdigit(c))
//     	printf ("数字じゃないよ\n");
//     if (isdigit(c))
//     	printf ("数字じゃないよ\n");

//     c = ' ';
//     if (ft_isdigit(c))
//     	printf ("数字じゃないよ\n");
//     if (isdigit(c))
//     	printf ("数字じゃないよ\n");

// 	c = '4';
//     if (ft_isdigit(c))
//     	printf ("数字だよ\n");
//     if (isdigit(c))
//     	printf ("数字だよ\n");
// }