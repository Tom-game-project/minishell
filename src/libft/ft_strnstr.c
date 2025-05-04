/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:22:37 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:02:30 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (*needle == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			n = 0;
			while (i + n < len && haystack[i + n] == needle[n] && needle[n])
				n++;
			if (needle[n] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
