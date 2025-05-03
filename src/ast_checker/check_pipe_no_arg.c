/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_no_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:57:21 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:03:10 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include <unistd.h>

t_syntax_result	check_pipe_no_arg(t_ast *ast)
{
	t_syntax_result	result;

	result = e_syntax_ok;
	if (ast->ope == e_ope_pipe
		&& (ast->left_ast == NULL || ast->right_ast == NULL))
		result = e_rdt_near_unexpected_token_pipe;
	return (result);
}
