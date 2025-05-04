/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_ex_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:15:40 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:27:29 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_anytype	alloc_ex_token(t_expand_token_type token_type, char *str)
{
	t_anytype	elem;

	elem.ex_token = (t_expand_token *)malloc(sizeof(t_expand_token));
	elem.ex_token->token_type = token_type;
	elem.ex_token->str = str;
	return (elem);
}
