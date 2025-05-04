/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:32:33 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/25 18:32:43 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	*__real_malloc(size_t size);

void	*__wrap_malloc(size_t size)
{
	void	*ptr;

	ptr = __real_malloc(size);
	if (ptr == NULL)
	{
		ft_putstr_fd("allocation error occured\n", STDERR_FILENO);
		exit(1);
	}
	return (ptr);
}
