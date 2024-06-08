/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:48:49 by kaara             #+#    #+#             */
/*   Updated: 2024/05/31 21:34:28 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dstsize -= 1;
	while (dstsize-- && *src != '\0')
		*dst++ = *src++;
	*dst++ = '\0';
	return (src_len);
}

// int main() 
// {
//     char d[10];
//     const char *s = "Hello, World!";
//     size_t needed = ft_strlcpy(d, s, 5);
//     printf("%s\n", d);
//     printf("%zu\n", needed);
//     size_t original = strlcpy(d, s, 6);
//     printf("%s\n", d);
//     printf("%zu\n", original);
// }
