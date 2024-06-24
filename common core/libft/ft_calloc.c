/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 03:37:42 by kaara             #+#    #+#             */
/*   Updated: 2024/06/24 21:36:16 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*test;

	test = malloc(count * size);
	if (!test)
		return (NULL);
	ft_bzero (test, count * size);
	return (test);
}

// int main() 
// {
//     int *array = (int*)ft_calloc(10, sizeof(int));
//     if (array == NULL)
//     {
//         perror("calloc failed");
//         return (0);
//     }
//     for (int i = 0; i < 10; i++) {
//         printf("%d", array[i]);
//     }
//     printf("\n");
//     free(array);
//     return (0);
// }
