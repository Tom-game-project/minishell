/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:56:18 by kaara             #+#    #+#             */
/*   Updated: 2024/06/06 19:43:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>

// int main (void)
// {
//     printf("%s",ft_strchr("teste", 'c'));
// 	printf("%s",strchr("teste", 'c'));
// 	printf("\n");
// 	printf("%s",ft_strchr("teste", 'e'));
// 	printf("%s",strchr("teste", 'e'));
// 	printf("\n");
// 	printf("%s",ft_strchr("teste", '\0'));
// 	printf("%s",strchr("teste", '\0'));
// 	printf("\n");
// 	printf("%s",ft_strchr("teste", 'a'));
// 	printf("%s",strchr("teste", 'a'));
// 	printf("\n");
// 	printf("%s",ft_strchr("teste", 'e' + 256));
// 	printf("%s",strchr("teste", 'e' + 256));
// 	printf("\n");
// 	printf("%s",ft_strchr("teste", 'e' + 1024));
// 	printf("%s",strchr("teste", 'e' + 1024));
// }
