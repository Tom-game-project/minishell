/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:09:47 by kaara             #+#    #+#             */
/*   Updated: 2024/05/31 21:56:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}

// int main()
// {
//     int	 i;
//     char array[10];
//     int	 i;
//     char array1[10];

//     i = 0;
//     ft_bzero(array, sizeof(array));
//     bzero(array1, sizeof(array1));

// 	if (array)
//     return 0;
// }
