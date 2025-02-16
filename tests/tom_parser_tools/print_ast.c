#include <stdlib.h>
#include "parser.h"
#include "list.h"

#include <stdio.h>

#define INDENT 4

static int print_str_list_for_test(t_str_list *lst)
{
	printf("[");
	while (lst != NULL)
	{
		printf("\"%s\", ", lst->str);
		lst = lst->next;
	}
	printf("]");
	return (0);
}


static int indent_print(char *str,  int depth)
{
	int i;

	i = 0;
	while (i < depth * INDENT)
	{
		printf(" ");
		i += 1;
	}
	printf("%s", str);
	return (0);
}

static int print_ope(t_operator ope)
{
	switch (ope) {
		case e_ope_none:
			printf("\"none\"");
		break;
		case e_ope_and: // &&
			printf("\"&&\"");
		break;
		case e_ope_or: // ||
			printf("\"||\"");
		break;
		case e_ope_redirect_i: // <
			printf("\"<\"");
		break;
		case e_ope_redirect_o:// >
			printf("\">\"");
		break;
		case e_ope_heredoc_i:// <<
			printf("\"<<\"");
		break;
		case e_ope_heredoc_o:// >>
			printf("\">>\"");
		break;
		case e_ope_pipe:// |
			printf("\"|\"");
		break;
		case e_ope_paren:// )
			printf("\"paren\"");
		break;
	}
	return (0);
}

int print_ast(t_ast *ast, int depth)
{
	indent_print("&(t_ast) {\n", depth);
	indent_print(".arg=", depth + 1);
	print_str_list_for_test(ast->arg);
	printf("\n");
	indent_print(".right_ast = ", depth + 1);
	printf("\n");
	// left_ast
	if (ast->left_ast != NULL)
		print_ast(ast->left_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	printf("\n");
	indent_print(".left_ast = ", depth + 1);
	printf("\n");
	// right_ast
	if (ast->right_ast != NULL)
		print_ast(ast->right_ast, depth + 2);
	else
		indent_print("NULL", depth + 2);
	printf("\n");
	indent_print(".ope = ", depth + 1);
	print_ope(ast->ope);
	printf("\n");
	indent_print("}", depth);
	return (0);
}
