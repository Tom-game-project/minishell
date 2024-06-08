/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:18:08 by kaara             #+#    #+#             */
/*   Updated: 2024/05/21 09:14:17 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pd;
	const char	*ps;

	pd = dest;
	ps = src;
	if (dest == NULL && src == NULL)
		return (0);
	while (n--)
		*pd++ = *ps++;
	return (dest);
}

// int main(void)
// {
// 	// char *src = "segfaulter";
// 	// char dest[10];
// 	// char *src2= "segfaulter";
// 	// char dest2[10];

// 	// ft_memcpy (dest, src, 10);
// 	// printf ("%s\n", dest);
// 	// memcpy (dest2, src2, 10);
// 	// printf ("%s\n", dest2);

// 	ft_memcpy(((void *)0), "segfaulter tu dois", 17);
// 	memcpy(((void *)0), "segfaulter tu dois", 17);

// 	return (0);
// }
