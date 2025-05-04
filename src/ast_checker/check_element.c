/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:53:24 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:53:52 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "parser.h"
#include "list.h"
#include <unistd.h>

t_syntax_result	check_element(t_ast *ast)
{
	int				i;
	int				tmp;
	t_str_list		*head;
	t_syntax_result	result;

	head = ast->arg;
	result = e_syntax_ok;
	while (head != NULL)
	{
		i = 0;
		while (*(head->ptr.str + i) != '\0')
		{
			if (*(head->ptr.str + i) == '(')
				result = e_syntax_near_unexpected_token_string;
			tmp = find_syntax(head->ptr.str + i);
			if (tmp > 0)
				i += tmp;
			else
				i++;
		}
		head = head->next;
	}
	return (result);
}
