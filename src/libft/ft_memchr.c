/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:19:02 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:00:25 by kaara            ###   ########.fr       */
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
