/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:38:26 by kaara             #+#    #+#             */
/*   Updated: 2024/06/24 20:05:21 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
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