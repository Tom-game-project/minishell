/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rdt_adjacent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:57:50 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 14:58:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "parser.h"

t_syntax_result	check_rdt_no_element(t_ast *ast)
{
	t_syntax_result	result;

	result = e_syntax_ok;
	if (is_enum_rdtope(ast->ope))
	{
		if (is_redirect_operators(ast->arg->ptr.str))
			result = e_rdt_near_unexpected_token_rdt;
	}
	return (result);
}
