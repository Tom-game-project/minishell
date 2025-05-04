/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_no_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:57:42 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 14:57:45 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ast_checker.h"
#include <stdio.h>

t_syntax_result	check_no_input(t_ast *ast)
{
	t_syntax_result	result;

	result = e_syntax_ok;
	if (ast->arg == NULL
		&& ast->ope == e_ope_none
		&& ast->left_ast == NULL
		&& ast->right_ast == NULL)
		result = e_no_input;
	return (result);
}
