#include "libft.h"
#include "list.h"
#include "parser.h"
#include <stdlib.h>

void	parser(t_ast **ast, char *input)
{
	char		*str;
	t_str_list	*next_input;
	t_str_list	*head;

	str = ft_strdup(input);
	*ast = allocation_ast();
	if (checker_str_ctl(input))
		next_input = separate_and_store_control_operators(*ast, &str);
	else if (checker_str_rdt(input))
		next_input = separate_and_store_redirect_operators(*ast, &str);
	else
	{
		separate_and_store_cmd_args(*ast, &str);
		return ;
	}
	head = next_input;
	parser(&((*ast)->left_ast), head->str);
	head = next_input->next;
	parser(&((*ast)->right_ast), head->str);
	str_list_clear(&next_input, free);
}
