#include "parser.h"
#include "libft.h"
#include "list.h"

static char *ctl_extract_operands(char *input);
static char *search_ctl_operater(char *input);
static void	store_head_element(t_ast  *ast, t_str_list **next_input, char *head_element);

t_str_list	*separate_and_store_control_operators(t_ast  *ast, char **input)
{
	t_str_list	*next_input;
	char		*head_element;

	if (input == NULL)
		return (NULL);
	next_input = NULL;
	head_element = search_ctl_operater(trim_isspc(*input));
	update_input(input, head_element);
	store_head_element(ast, &next_input, head_element);
	if (head_element == NULL)
		return (next_input);
	free(head_element);
	next_input->next = separate_and_store_control_operators(ast, input);
	return (next_input);
}

static char *search_ctl_operater(char *input)
{
	char *head_element;

	if (input[0] == '"')
		head_element = ft_substr(input, 0, find_chr(input + 1, '"') + 2);
	else if (input[0] == '\'')
		head_element = ft_substr(input, 0, find_chr(input + 1, '\'') + 2);
	else if (ft_strncmp(input,"$(", 2) == 0)
		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
	else if (input[0] == '(')
		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
	else if (ft_strncmp(input, "&&", 2) == 0)
		head_element = ft_substr(input, 0, 2);
	else if (ft_strncmp(input, "||", 2) == 0)
		head_element = ft_substr(input, 0, 2);
	else
		head_element = ctl_extract_operands(input);
	if (*head_element == '\0')
		return (NULL);
	return (head_element);
}

static char *ctl_extract_operands(char *input)
{
	size_t	i;
	char	*head_element;

	i = 0;
	while (input[i] != '\0' && is_control_operators(input + i) == false)
		i++;
	head_element = ft_substr(input, 0, i);
	return (head_element);
}

static void	store_head_element(t_ast  *ast, t_str_list **next_input, char *head_element)
{
	if (ft_strncmp(head_element, "&&", 2) == 0)
		ast->ope = e_ope_and;
	else if (ft_strncmp(head_element, "||", 2) == 0)
		ast->ope = e_ope_or;
	else
		str_list_push(next_input, ft_strdup(head_element));
}
