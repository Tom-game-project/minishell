/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 03:40:01 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:00:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n);

char	*ft_itoa(int n)
{
	int				len;
	char			*result;
	unsigned int	un;

	len = nbrlen(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		un = (unsigned int)-n;
	}
	else
		un = (unsigned int)n;
	while (un)
	{
		result[len--] = un % 10 + '0';
		un /= 10;
	}
	return (result);
}

static int	nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
