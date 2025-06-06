/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:27:28 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:28:18 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "dict.h"
#include "err_msg.h"
#include "libft.h"
#include "loop_private.h"
#include "parser.h"
#include "tom_parser.h"
#include <limits.h>
#include <unistd.h>

// for test
#include "test_tools.h"

static t_ast	*parser_wrap(char *input, bool *syntax_err_flag)
{
	t_ast	*ast;

	ast = NULL;
	*syntax_err_flag = e_result_paren_not_closed_err == tom_parser(input, &ast);
	if (*syntax_err_flag)
		report_parser_syntax_error();
	else
		debug_dprintf(STDERR_FILENO, "\ninput : %s\n\n", input);
	return (ast);
}

///
///
int	exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status)
{
	t_ast			*ast;
	bool			syntax_error_flag;
	t_syntax_result	result;

	if (INT_MAX < ft_strlen(str))
	{
		report_too_long_input();
		*exit_status = 1;
		return (0);
	}
	ast = parser_wrap(str, &syntax_error_flag);
	if (syntax_error_flag == 1)
	{
		*exit_status = 1;
		return (clear_ast(&ast), 0);
	}
	result = ast_checker(ast);
	if (result == e_no_input)
		return (clear_ast(&ast), 0);
	*exit_status = exec_ast(ast, env_dict, result);
	return (clear_ast(&ast), 1);
}
