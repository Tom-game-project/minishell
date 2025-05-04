/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_checker_wrap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:56:09 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:02:18 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "parser.h"
#include <unistd.h>

bool	ast_checker_wrap2(t_ast **ast)
{
	t_syntax_result	result;

	result = ast_checker(*ast);
	if (result == e_syntax_ok)
		return (true);
	if (result != e_syntax_ok && result != e_no_input)
		print_checker_result(result);
	clear_ast(ast);
	*ast = NULL;
	return (false);
}
