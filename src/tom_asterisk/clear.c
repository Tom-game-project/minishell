/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:54:41 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/02 18:54:42 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

static void free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}

// リストの中のリストをクリアにする
static void clear_token_list(t_anytype elem)
{
	void_list_clear(&elem.list, free_ex_token);
}


int clear_split_token_list(t_void_list **token_list)
{
	void_list_clear(token_list, clear_token_list);
	return (0);
}

