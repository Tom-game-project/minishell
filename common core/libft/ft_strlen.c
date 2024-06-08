/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:11:03 by kaara             #+#    #+#             */
/*   Updated: 2024/06/03 19:32:45 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}

// int	main(void)
// {
// 	char *str = "k"; 
// 	printf("%zu\n", ft_strlen(str));

// 	char *str1 = "k";
// 	printf("%zu\n", strlen(str1));
// 	return (0);
// }
