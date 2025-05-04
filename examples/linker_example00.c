/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:10:42 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:11:03 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// __real_malloc は、元の malloc へリンク時にマッピングされる
void	*__real_malloc(size_t size);

void	*__wrap_malloc(size_t size)
{
	printf("[Custom malloc] Allocating %zu bytes\n", size);
	return (__real_malloc(size));
}

/// ```bash
/// gcc -Wl,--wrap=malloc -o my_program  examples/linker_example00.c
/// ```
int	main(void)
{
	char	*a;

	a = malloc(sizeof(char *) * 100);
	free(a);
	return (0);
}
