#include "libft.h"
#include "list.h"
#include "parser.h"
#include <stdlib.h>

t_parse_result get_next_input(t_ast **ast, t_str_list	**next_input, char **str);

t_parse_result	parser(t_ast **ast, char *input)
{
	char			*str;
	t_str_list		*next_input;
	t_str_list		*head;
	t_parse_result	result;

	if (input == NULL || *input == '\0')
		return (e_result_ok);
	next_input = NULL;
	if (syntax_checker(input) == false)
		return (e_result_paren_not_closed_err);
	str = ft_strdup(input);
	*ast = allocation_ast();
	result = get_next_input(ast, &next_input, &str);
	if (next_input == NULL)
		return (result);
	head = next_input;
	result = parser(&((*ast)->left_ast), head->ptr.str);
	if (result == e_result_ok && next_input->next != NULL)
	{
		head = next_input->next;
		result = parser(&((*ast)->right_ast), head->ptr.str);
	}
	free(str);
	str_list_clear(&next_input, free);
	return (result);
}

t_parse_result get_next_input(t_ast **ast, t_str_list	**next_input, char **str)
{
	t_parse_result result;

	result = e_result_ok;
	if (checker_str_ctl(*str))
		*next_input = separate_and_store_control_operators(*ast, str);
	else if (checker_str_pipe(*str))
		*next_input = separate_and_store_pipe_operators(*ast, str);
	else if (checker_str_rdt(*str))
		*next_input = separate_and_store_redirect_operators(*ast, str);
	else
	{
		result = separate_and_store_cmd_args(*ast, str);
		free(*str);
		return (result);
	}
	return (result);
}
