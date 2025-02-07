#include "libft.h"
#include "list.h"
#include "parser.h"
#include <stdlib.h>

void	parser(t_ast **ast, char *input)
{
	char		*str;
	t_str_list	*next_input;
	t_str_list	*head;

	head = next_input;
	str = ft_strdup(input);
	*ast = allocation_ast();
	if (checker_str_ctl(input))
		separate_and_store_control_operators(*ast, &str);
	else if (checker_str_rdt(input))
		separate_and_store_redirect_operators(*ast, &str);
	else
		separate_and_store_cmd_args(*ast, &str);
	parser(ast->left_ast, head->str);
	head = next_input->next;
	parser(ast->right_ast, head->str);
}


