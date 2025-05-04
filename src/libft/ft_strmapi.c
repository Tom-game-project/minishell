/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 04:12:42 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:02:19 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
