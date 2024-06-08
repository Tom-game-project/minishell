/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:32:36 by kaara             #+#    #+#             */
/*   Updated: 2024/05/31 23:47:07 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t n)
{
	unsigned char	*p;

	p = buf;
	while (n-- > 0)
		*p++ = (unsigned char)c;
	return (buf);
}

// int main()
// {
//     char *array = NULL;

//     ft_memset(array, 'x', 5);
//     printf("%s", array);
//     return (0);
// }
