/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:22:37 by kaara             #+#    #+#             */
/*   Updated: 2024/06/05 21:29:37 by kaara            ###   ########.fr       */
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

// int	main(void)
// {
// 	char s1[20] = "MZIRIBMZIRIBMZE123";
// 	char s2[20] = "MZIRIBMZE";
//     printf("%s\n", ft_strnstr(s1, s2, strlen(s2)));

// 	char s12[20] = "MZIRIBMZIRIBMZE123";
// 	char s22[20] = "MZIRIBMZE";
//     printf("%s\n", strnstr(s12, s22, strlen(s2)));
// }