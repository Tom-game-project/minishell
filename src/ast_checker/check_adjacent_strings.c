/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_adjacent_strings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:56:16 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 14:56:16 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "parser.h"
#include <unistd.h>

t_syntax_result	check_adjacent_strings(t_ast *ast)
{
	t_syntax_result	result;

	result = e_syntax_ok;
	if (ast->ope == e_ope_paren)
	{
		if (ast->right_ast != NULL)
			result = e_syntax_near_unexpected_token_string;
	}
	if (ast->arg != NULL)
	{
		if (ast->right_ast != NULL && ast->right_ast->ope == e_ope_paren)
			result = e_syntax_near_unexpected_token_string;
	}
	return (result);
}
