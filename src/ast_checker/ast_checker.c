/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:56:12 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:02:07 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "parser.h"
#include <unistd.h>

#define ERROR_CHECK_FUNCS_LEN 7

static t_syntax_result	syntax_check(t_ast	*ast);

t_syntax_result	ast_checker(t_ast	*ast)
{
	t_syntax_result	check_result;

	if (ast == NULL)
		return (e_syntax_ok);
	check_result = syntax_check(ast);
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = ast_checker(ast->left_ast);
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = ast_checker(ast->right_ast);
	return (check_result);
}
// typedef t_syntax_result (*t_check_func)(t_ast *);

static t_syntax_result	syntax_check(t_ast	*ast)
{
	t_syntax_result	check_result;
	t_check_func	funcs[ERROR_CHECK_FUNCS_LEN];
	int				i;

	funcs[0] = check_no_input;
	funcs[1] = check_ctl_no_element;
	funcs[2] = check_pipe_no_arg;
	funcs[3] = check_rdt_no_arg;
	funcs[4] = check_rdt_no_element;
	funcs[5] = check_element;
	funcs[6] = check_adjacent_strings;
	i = 0;
	check_result = e_syntax_ok;
	while (i < ERROR_CHECK_FUNCS_LEN)
	{
		check_result = funcs[i](ast);
		if (check_result != e_syntax_ok)
			break ;
		i += 1;
	}
	return (check_result);
}
