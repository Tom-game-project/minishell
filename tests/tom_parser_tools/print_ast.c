#include <stdlib.h>
#include "parser.h"
#include "list.h"

#include <stdio.h>
#include <unistd.h>

#define INDENT 4

static int print_str_list_for_test(t_str_list *lst)
{
	dprintf(STDERR_FILENO, "[");
	while (lst != NULL)
	{
		dprintf(STDERR_FILENO, "\"%s\", ", lst->ptr.str);
		lst = lst->next;
	}
	dprintf(STDERR_FILENO, "]");
	return (0);
}


static int indent_print(char *str,  int depth)
{
	int i;

	i = 0;
	while (i < depth * INDENT)
	{
		dprintf(STDERR_FILENO, " ");
		i += 1;
	}
	dprintf(STDERR_FILENO, "%s", str);
	return (0);
}

static int print_ope(t_operator ope)
{
	switch (ope) {
		case e_ope_none:
			dprintf(STDERR_FILENO, "\"none\"");
		break;
		case e_ope_and: // &&
			dprintf(STDERR_FILENO, "\"&&\"");
		break;
		case e_ope_or: // ||
			dprintf(STDERR_FILENO, "\"||\"");
		break;
		case e_ope_redirect_i: // <
			dprintf(STDERR_FILENO, "\"<\"");
		break;
		case e_ope_redirect_o:// >
			dprintf(STDERR_FILENO, "\">\"");
		break;
		case e_ope_heredoc_i:// <<
			dprintf(STDERR_FILENO, "\"<<\"");
		break;
		case e_ope_heredoc_o:// >>
			dprintf(STDERR_FILENO, "\">>\"");
		break;
		case e_ope_pipe:// |
			dprintf(STDERR_FILENO, "\"|\"");
		break;
		case e_ope_paren:// )
			dprintf(STDERR_FILENO, "\"paren\"");
		break;
	}
	return (0);
}

int print_ast(t_ast *ast, int depth)
{
	indent_print("&(t_ast) {\n", depth);
	indent_print(".arg=", depth + 1);
	print_str_list_for_test(ast->arg);
	dprintf(STDERR_FILENO, "\n");
	indent_print(".left_ast = ", depth + 1);
	dprintf(STDERR_FILENO, "\n");
	// left_ast
	if (ast->left_ast != NULL)
		print_ast(ast->left_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	dprintf(STDERR_FILENO, "\n");
	indent_print(".right_ast = ", depth + 1);
	dprintf(STDERR_FILENO, "\n");
	// right_ast
	if (ast->right_ast != NULL)
		print_ast(ast->right_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	dprintf(STDERR_FILENO, "\n");
	indent_print(".ope = ", depth + 1);
	print_ope(ast->ope);
	dprintf(STDERR_FILENO, "\n");
	indent_print("}\n", depth);
	return (0);
}
