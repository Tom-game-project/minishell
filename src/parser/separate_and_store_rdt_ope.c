#include "parser.h"
#include "libft.h"

static char *search_rdt_operater(char *input);
static char *rdt_extract_operands(char *input);
static void	store_head_element(t_ast  *ast, t_str_list **next_input, char *head_element);

t_str_list	*separate_and_store_redirect_operators(t_ast  *ast, char **input)
{
	t_str_list	*next_input;
	char *head_element;

	if (input == NULL)
		return (NULL);
	next_input = NULL;
	head_element = search_rdt_operater(trim_isspc(*input));
	if (head_element == NULL)
		return (next_input);
	update_input(input, head_element);
	store_head_element(ast, &next_input, head_element);
	free(head_element);
	next_input->next = separate_and_store_redirect_operators(ast, input);
	return (next_input);
}

static char *search_rdt_operater(char *input)
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
	else if (ft_strncmp(input, ">>", 2) == 0)
		head_element = ft_substr(input, 0, 2);
	else if (ft_strncmp(input, "<<", 2) == 0)
		head_element = ft_substr(input, 0, 2);
	else if (input[0] == '>')
		head_element = ft_substr(input, 0, 1);
	else if (input[0] == '<')
		head_element = ft_substr(input, 0, 1);
	else
		head_element = rdt_extract_operands(input);
	if (*head_element == '\0')
		return (NULL);
	return (head_element);
}

static char *rdt_extract_operands(char *input)
{
	size_t	i;
	char	*head_element;

	i = 0;
	while (input[i] != '\0' && is_redirect_operators(input + i) == false)
		i++;
	head_element = ft_substr(input, 0, i);
	return (head_element);
}

static void	store_head_element(t_ast  *ast, t_str_list **next_input, char *head_element)
{
	if (head_element[0] == '|')
		ast->ope = e_ope_pipe;
	else if (ft_strncmp(head_element, ">>", 2) == 0)
		ast->ope = e_ope_heredoc_o;
	else if (ft_strncmp(head_element, "<<", 2) == 0)
		ast->ope = e_ope_heredoc_i;
	else if (head_element[0] == '>')
		ast->ope = e_ope_redirect_o;
	else if (head_element[0] == '<')
		ast->ope = e_ope_redirect_i;
	else
		str_list_push(next_input, ft_strdup(head_element));

}
