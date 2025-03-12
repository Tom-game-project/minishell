#include "parser.h"
#include <unistd.h>
#include "test_tools.h"

#define INDENT 4

#ifdef DEBUG
#include <stdlib.h>
#include "list.h"
#include <stdio.h>
static int print_str_list_for_test(t_str_list *lst)
{
	my_dprintf(STDERR_FILENO, "[");
	while (lst != NULL)
	{
		my_dprintf(STDERR_FILENO, "\"%s\", ", lst->ptr.str);
		lst = lst->next;
	}
	my_dprintf(STDERR_FILENO, "]");
	return (0);
}

static int indent_print(char *str,  int depth)
{
	int i;

	i = 0;
	while (i < depth * INDENT)
	{
		my_dprintf(STDERR_FILENO, " ");
		i += 1;
	}
	my_dprintf(STDERR_FILENO, "%s", str);
	return (0);
}

static int print_ope(t_operator ope)
{
	switch (ope) {
		case e_ope_none:
			my_dprintf(STDERR_FILENO, "\"none\"");
		break;
		case e_ope_and: // &&
			my_dprintf(STDERR_FILENO, "\"&&\"");
		break;
		case e_ope_or: // ||
			my_dprintf(STDERR_FILENO, "\"||\"");
		break;
		case e_ope_redirect_i: // <
			my_dprintf(STDERR_FILENO, "\"<\"");
		break;
		case e_ope_redirect_o:// >
			my_dprintf(STDERR_FILENO, "\">\"");
		break;
		case e_ope_heredoc_i:// <<
			my_dprintf(STDERR_FILENO, "\"<<\"");
		break;
		case e_ope_heredoc_o:// >>
			my_dprintf(STDERR_FILENO, "\">>\"");
		break;
		case e_ope_pipe:// |
			my_dprintf(STDERR_FILENO, "\"|\"");
		break;
		case e_ope_paren:// )
			my_dprintf(STDERR_FILENO, "\"paren\"");
		break;
	}
	return (0);
}
int print_ast(t_ast *ast, int depth)
{
	indent_print("&(t_ast) {\n", depth);
	indent_print(".arg=", depth + 1);
	print_str_list_for_test(ast->arg);
	my_dprintf(STDERR_FILENO, "\n");
	indent_print(".left_ast = ", depth + 1);
	my_dprintf(STDERR_FILENO, "\n");
	if (ast->left_ast != NULL)
		print_ast(ast->left_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	my_dprintf(STDERR_FILENO, "\n");
	indent_print(".right_ast = ", depth + 1);
	my_dprintf(STDERR_FILENO, "\n");
	if (ast->right_ast != NULL)
		print_ast(ast->right_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	my_dprintf(STDERR_FILENO, "\n");
	indent_print(".ope = ", depth + 1);
	print_ope(ast->ope);
	my_dprintf(STDERR_FILENO, "\n");
	indent_print("}\n", depth);
	return (0);
}
#else

int print_ast(t_ast *ast, int depth)
{
	(void) ast;
	(void) depth;
	return (0);
}
#endif
