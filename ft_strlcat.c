/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:13:36 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:02:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	mix_len;
	size_t	cpy_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	mix_len = dst_len + src_len;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	cpy_len = dstsize - dst_len - 1;
	while (cpy_len > 0 && *src != '\0')
	{
		dst[dst_len++] = *src++;
		cpy_len--;
	}
	dst[dst_len] = '\0';
	return (mix_len);
}
