#include "libft.h"
#include "list.h"
#include "parser.h"
#include <stdlib.h>

t_parse_result	parser(t_ast **ast, char *input)
{
	t_parse_result	result;
	char			*str;
	t_str_list		*next_input;
	t_str_list		*head;

	result = e_result_ok;
	if (input == NULL)
		return (result);
	result = syntax_checker(input);
	if (result == e_result_paren_not_closed_err)
		return (result);
	str = ft_strdup(input);
	*ast = allocation_ast();
	//別関数へ
	if (checker_str_ctl(input))
		next_input = separate_and_store_control_operators(*ast, &str);
	else if (checker_str_pipe(input))
		next_input = separate_and_store_pipe_operators(*ast, &str);
	else if (checker_str_rdt(input))
		next_input = separate_and_store_redirect_operators(*ast, &str);
	else
	{
		separate_and_store_cmd_args(*ast, &str);
		free(str);
		return (result);
	}
	//
	head = next_input;
	result = parser(&((*ast)->left_ast), head->ptr.str);
	if (next_input->next != NULL)//sonoutibetukannsuudecheck
		head = next_input->next;
	result = parser(&((*ast)->right_ast), head->ptr.str);
	free(str);
	str_list_clear(&next_input, free);
	return (result);
}
