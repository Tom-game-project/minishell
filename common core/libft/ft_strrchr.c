/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:19:55 by kaara             #+#    #+#             */
/*   Updated: 2024/06/08 17:15:52 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (len > 0)
	{
		len--;
		if (s[len] == (char)c)
			return ((char *)s + len);
	}
	return (NULL);
}

// char    *ft_strrchr(const char *s, int c)
// {
//     int            len;
//     const char    *curr;

//     len = ft_strlen(s);
//     curr = s + len;
//     while (s <= curr)
//     {
//         if (*curr == (char)c)
//             return ((char *)curr);
//         curr--;
//     }
//     return (NULL);
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int			i;
// 	const char *result;

// 	result = NULL;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			result = &s[i];
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)&s[i]);
// 	return ((char *)result);
// }

// #include <stdio.h>
// #include <string.h>
// int main (void)
// {
//  printf("%s",ft_strrchr(strdup("123456789"), 'a'));
// 	printf("%s",strrchr("123456789", 'a'));
// 	printf("\n");
// 	printf("%s",ft_strrchr("", 'x'));
// 	printf("%s",strrchr("", 'x'));
// 	printf("\n");
// 	printf("%s",ft_strrchr("teste", '\0'));
// 	printf("%s",strrchr("teste", '\0'));
// 	printf("\n");
// 	printf("%s",ft_strrchr("teste", 'e'));
// 	printf("%s",strrchr("teste", 'e'));
// 	printf("\n");
// 	printf("%s",ft_strrchr("teste", 'e' + 256));
// 	printf("%s",strrchr("teste", 'e' + 256));
// 	printf("\n");
// 	printf("%s",ft_strrchr("teste", 'e' + 1024));
// 	printf("%s",strrchr("teste", 'e' + 1024));
// 	printf("\n");
// 	printf("%s",ft_strrchr("pepe y cparlos", 'c'));
// 	printf("%s",strrchr("pepe y cparlos", 'c'));
// }
