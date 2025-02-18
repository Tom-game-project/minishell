#include "libft.h"
#include "list.h"
#include "parser.h"
#include <stdlib.h>

int	parser(t_ast **ast, char *input)
{
	int			err;
	char		*str;
	t_str_list	*next_input;
	t_str_list	*head;

	err = 0;
	if (input == NULL)
		return (err);
	if (syntax_checker(input) < 0)
	{
		err = -1;
		return (err);
	}
	str = ft_strdup(input);
	*ast = allocation_ast();
	//別関数へ
	if (checker_str_ctl(input))
		next_input = separate_and_store_control_operators(*ast, &str);
	else if (checker_str_rdt(input))
		next_input = separate_and_store_redirect_operators(*ast, &str);
	else
	{
		separate_and_store_cmd_args(*ast, &str);
		free(str);
		return (err);
	}
	//
	head = next_input;
	err = parser(&((*ast)->left_ast), head->str);
	head = next_input->next;
	err = parser(&((*ast)->right_ast), head->str);
	free(str);
	str_list_clear(&next_input, free);
	return (err);
}
