/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:27:34 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:29:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "dict.h"
#include "exec.h"
#include "parser.h"
#include "test_tools.h"

int	exec_ast(t_ast *ast, t_str_dict **env_dict, t_syntax_result result)
{
	debug_dprintf(STDERR_FILENO, "ORIGIN PID (%d)\n", debug_getpid());
	if (ast == NULL)
		return (1);
	if (print_checker_result(result))
	{
		print_ast(ast, 0);
		return (exec(ast, env_dict));
	}
	else
		return (1);
	return (0);
}
