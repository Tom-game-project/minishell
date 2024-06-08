/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:11:27 by kaara             #+#    #+#             */
/*   Updated: 2024/06/06 20:40:16 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char str)
{
	if ((str >= 9 && str <= 13) || str == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

// int	main(void)
// {
// 	char	*str;
// 	int		result;
// 	int		atoi_result;

// 	str = "+-23";
// 	result = ft_atoi(str);
// 	atoi_result = atoi(str);
// 	printf ("%d %d\n", result,atoi_result);

// 	str = "d469 \n";
// 	result = ft_atoi(str);
// 	atoi_result = atoi(str);
// 	printf ("%d %d\n", result,atoi_result);

// 	str = "str";
// 	result = ft_atoi(str);
// 	atoi_result = atoi(str);
// 	printf ("%d %d\n", result,atoi_result);

// 	str = "--2343";
// 	result = ft_atoi(str);
// 	atoi_result = atoi(str);
// 	printf ("%d %d\n", result,atoi_result);

// 	str = " 			23";
// 	result = ft_atoi(str);
// 	atoi_result = atoi(str);
// 	printf ("%d %d\n", result,atoi_result);

// 	str = "2147483648";
// 	result = ft_atoi(str);
// 	atoi_result = atoi(str);
// 	printf ("%d %d\n", result,atoi_result);
// }
