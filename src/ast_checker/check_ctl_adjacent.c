/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ctl_adjacent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:56:22 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:02:30 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "parser.h"
#include <unistd.h>

t_syntax_result	check_ctl_no_element(t_ast *ast)
{
	t_syntax_result	result;

	result = e_syntax_ok;
	if (ast->ope == e_ope_and)
	{
		if (ast->left_ast == NULL || ast->right_ast == NULL)
			result = e_ctl_near_unexpected_token_and;
	}
	else if (ast->ope == e_ope_or)
	{
		if (ast->left_ast == NULL || ast->right_ast == NULL)
			result = e_ctl_near_unexpected_token_or;
	}
	return (result);
}
