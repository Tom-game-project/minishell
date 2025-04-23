/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:31:38 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 21:40:20 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "private.h"

static int	set_next_anchor_and_depth(char c, t_anchor *p, int *depth)
{
	if (*p == e_outof_q)
	{
		if (c == '\'')
			*p = e_in_q;
		else if (c == '"')
			*p = e_in_dq;
		else if (c == '(')
			*depth += 1;
		else if (c == ')')
			*depth -= 1;
	}
	else if (*p == e_in_dq)
	{
		if (c == '"')
			*p = e_outof_q;
	}
	else if (*p == e_in_q)
	{
		if (c == '\'')
			*p = e_outof_q;
	}
	return (0);
}

bool	tom_syntax_checker(char *input)
{
	t_char_list	*lst;
	t_anchor	p;
	char		c;
	int			depth;

	lst = NULL;
	p = e_outof_q;
	depth = 0;
	char_list_push_str(&lst, input);
	while (char_list_len(lst) != 0)
	{
		c = char_list_pop(&lst, 0);
		set_next_anchor_and_depth(c, &p, &depth);
	}
	char_list_clear(&lst);
	return (depth == 0 && p == e_outof_q);
}
