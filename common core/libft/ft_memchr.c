/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:19:02 by kaara             #+#    #+#             */
/*   Updated: 2024/06/22 17:29:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		ucc;

	p = (const unsigned char *)buf;
	ucc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*p == ucc)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

// int	main()
// {
// 	char	*array = "/|\x12\xff\x09\x42\2002\42|\\";
// 	char	*result = ft_memchr(array, '\200', 10);

// 	if (result != NULL)
// 		printf ("%s", result);
// 	else
// 		printf ("ないよ\n");
// 	return (0);
// }
