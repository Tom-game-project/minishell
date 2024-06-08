/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:13:36 by kaara             #+#    #+#             */
/*   Updated: 2024/05/31 23:58:27 by kaara            ###   ########.fr       */
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

// int main(void)
// {
//     char pd[20] = "helloworld";
//     char *ps = "world";
//     printf("%zu\n", strlcat(pd, ps, 13));
//     printf("%s\n", pd);
//     char pd2[20] = "helloworld";
//     char *ps2 = "world";
//     printf("%zu\n", ft_strlcat(pd2, ps2, 13));
//     printf("%s\n", pd2);
// 	return (0);
// }
