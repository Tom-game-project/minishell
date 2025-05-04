/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_clone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:07 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:25:34 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

///
///
/// ```c
/// #include "libft.h"
/// str_list_clone(a, ft_strdup);
/// ```
///
///
/// ```c
/// char *f(char *a){
///	 return (a);
/// }
/// str_list_clone(a, f);
/// ```
t_str_list	*str_list_clone(t_str_list *a, char *(*f)(char *))
{
	t_str_list	*rl;

	rl = NULL;
	while (a != NULL)
	{
		str_list_push(&rl, f(a->ptr.str));
		a = a->next;
	}
	return (rl);
}
