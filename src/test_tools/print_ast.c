/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:02:31 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:08:19 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include "test_tools.h"
#include <stdlib.h>
#include "list.h"
#include <stdio.h>

#define INDENT 4

#ifdef DEBUG

static int	print_str_list_for_test(t_str_list *lst)
{
	debug_dprintf(STDERR_FILENO, "[");
	while (lst != NULL)
	{
		debug_dprintf(STDERR_FILENO, "\"%s\", ", lst->ptr.str);
		lst = lst->next;
	}
	debug_dprintf(STDERR_FILENO, "]");
	return (0);
}

static int	indent_print(char *str, int depth)
{
	int	i;

	i = 0;
	while (i < depth * INDENT)
	{
		debug_dprintf(STDERR_FILENO, " ");
		i += 1;
	}
	debug_dprintf(STDERR_FILENO, "%s", str);
	return (0);
}

static int	print_ope(t_operator ope)
{
	if (ope == e_ope_none)
		debug_dprintf(STDERR_FILENO, "\"none\"");
	else if (ope == e_ope_and)
		debug_dprintf(STDERR_FILENO, "\"&&\"");
	else if (ope == e_ope_or)
		debug_dprintf(STDERR_FILENO, "\"||\"");
	else if (ope == e_ope_redirect_i)
		debug_dprintf(STDERR_FILENO, "\"<\"");
	else if (ope == e_ope_redirect_o)
		debug_dprintf(STDERR_FILENO, "\">\"");
	else if (ope == e_ope_heredoc_i)
		debug_dprintf(STDERR_FILENO, "\"<<\"");
	else if (ope == e_ope_heredoc_o)
		debug_dprintf(STDERR_FILENO, "\">>\"");
	else if (ope == e_ope_pipe)
		debug_dprintf(STDERR_FILENO, "\"|\"");
	else if (ope == e_ope_paren)
		debug_dprintf(STDERR_FILENO, "\"paren\"");
	return (0);
}

int	print_ast(t_ast *ast, int depth)
{
	indent_print("&(t_ast) {\n", depth);
	indent_print(".arg=", depth + 1);
	print_str_list_for_test(ast->arg);
	debug_dprintf(STDERR_FILENO, "\n");
	indent_print(".left_ast = ", depth + 1);
	debug_dprintf(STDERR_FILENO, "\n");
	if (ast->left_ast != NULL)
		print_ast(ast->left_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	debug_dprintf(STDERR_FILENO, "\n");
	indent_print(".right_ast = ", depth + 1);
	debug_dprintf(STDERR_FILENO, "\n");
	if (ast->right_ast != NULL)
		print_ast(ast->right_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	debug_dprintf(STDERR_FILENO, "\n");
	indent_print(".ope = ", depth + 1);
	print_ope(ast->ope);
	debug_dprintf(STDERR_FILENO, "\n");
	indent_print("}\n", depth);
	return (0);
}
#else

int	print_ast(t_ast *ast, int depth)
{
	(void) ast;
	(void) depth;
	return (0);
}
#endif
