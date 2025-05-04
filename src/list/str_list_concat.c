/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_concat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:46 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:25:47 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "str_list.h"

/// ```
/// a -> (0) -> (1) -> NULL
/// b -> (2) -> (3) -> NULL
/// ```
///
///
/// ```
/// a -> (0) -> (1) -> (2) -> (3) -> NULL
/// b -> (2) -> (3) -> NULL
/// ```
/// ## NOTE
///
int	str_list_concat(t_str_list **a, t_str_list *b)
{
	return (void_list_concat(a, b));
}
