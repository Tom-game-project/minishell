#include "parser.h"
#include "libft.h"
#include "list.h"

#include <stdio.h>

static t_str_list	*store_left_next_input(char **input);
static void	store_ctlope_ast(t_ast	**ast, char **input);
static t_str_list	*store_right_next_input(char	*input);
static char *search_ctl_operater(char *input);

t_str_list	*separate_and_store_control_operators(t_ast  *ast, char **input)
{
	t_str_list	*next_input;

	next_input = store_left_next_input(input);
	store_ctlope_ast(&ast, input);
	next_input->next = store_right_next_input(*input);
	return (next_input);
}

t_str_list	*store_left_next_input(char **input)
{
	t_str_list	*next_input;
	char		*after_trim;
	char		*head_element;

	next_input = NULL;
	if (**input == '\0')
		return (next_input);
	after_trim = trim_isspc(*input);
	head_element = search_ctl_operater(after_trim);
	if (checker_str_ctl(head_element))
	{
		free(head_element);
		head_element = NULL;
	}
	update_input(input, head_element);
	str_list_push(&next_input, trim_isspc(head_element));
	free(after_trim);
	free(head_element);
	return (next_input);
}

void	store_ctlope_ast(t_ast	**ast, char **input)
{
	char		*after_trim;
	char		*head_element;

	if (**input == '\0')
		return ;
	after_trim = trim_isspc(*input);
	head_element = search_ctl_operater(after_trim);
	update_input(input, head_element);
	if (ft_strncmp(head_element, "&&", 2) == 0)
		(*ast)->ope = e_ope_and;
	else if (ft_strncmp(head_element, "||", 2) == 0)
		(*ast)->ope = e_ope_or;
	free(after_trim);
	free(head_element);
	return ;
}

t_str_list	*store_right_next_input(char	*input)
{
	char		*after_trim;
	t_str_list	*next_input;

	after_trim = trim_isspc(input);
	if (*after_trim == '\0')
	{
		free(after_trim);
		after_trim = NULL;
	}
	next_input = NULL;
	str_list_push(&next_input, after_trim);
	return (next_input);
}

static char *search_ctl_operater(char *input)
{
	char *head_element;

	if (ft_strncmp(input, "||", 2) == 0)
		head_element = ft_strdup("||");
	else if (ft_strncmp(input, "&&", 2) == 0)
		head_element = ft_strdup("&&");
	else
		head_element = ft_substr(input, 0, str_ctl_len(input));
	return (head_element);
}
