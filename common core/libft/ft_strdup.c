/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:09:29 by kaara             #+#    #+#             */
/*   Updated: 2024/05/24 04:56:21 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*srccpy;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	srccpy = (char *)malloc(size + 1);
	if (!srccpy)
		return (NULL);
	while (i < size)
	{
		srccpy[i] = src[i];
		i++;
	}
	srccpy[size] = '\0';
	return (srccpy);
}
// #include <stdio.h>

// int	main(void)
// {
//     char *copy;
//     char *src =	"hello world";
//     copy = ft_strdup(src);
//     if (copy)
//     {
// 		printf ("%s", copy);
//     	free(copy);
//     }
//     return (0);
// }