#include "parser.h"
#include "libft.h"

static char *search_rdt_operater(char *input);
static char *rdt_extract_operands(char *input);
static void store_head_element(t_ast  *ast, char *head_element);

t_ast   *separate_and_store_redirect_operators(t_ast  *ast, char **input)
{
	char *head_element;

	if (*input == NULL)
		return (NULL);
	head_element = search_rdt_operater(*input);
	if (head_element == NULL)
		return (NULL);
	update_input(input, head_element);
	store_head_element(ast, head_element);
	free(head_element);
	ast->right_ast = allocation_ast();
	ast->right_ast = separate_and_store_redirect_operators(ast->right_ast, input);
	return (ast);
}

static char *search_rdt_operater(char *input)
{
	char *head_element;

	if (*input[0] == '|')
		head_element = ft_strdup("|");
	else if (ft_strncmp(*input, ">>", 2) == 0)
		head_element = ft_strdup(">>");
	else if (ft_strncmp(*input, "<<", 2) == 0)
		head_element = ft_strdup("<<");
	else if (*input[0] == '>')
		head_element = ft_strdup(">");
	else if (*input[0] == '<')
		head_element = ft_strdup("<");
	else
		head_element = rdt_extract_operands(*input);
	return (head_element);
}

static char *rdt_extract_operands(char *input)
{
	size_t	i;
	char	*head_element;

	i = 0;
	while (input[i] != '\0' && is_redirect_operators(input + i))
		i++;
	if (i == 0)
		return (NULL);
	head_element = ft_substr(input, 0, i);
	return (head_element);
}

static void store_head_element(t_ast  *ast, char *head_element)
{
	tmp = ft_strtrim(head_element, " ");
	free(head_element);
	head_element = tmp;
	if (head_element[0] == '|')
		ast->rdt = e_rdtope_pipe;
	else if (ft_strncmp(head_element, ">>", 2) == 0)
		ast->rdt = e_rdtope_heredoc_o;
	else if (ft_strncmp(head_element, "<<", 2) == 0)
		ast->rdt = e_rdtope_heredoc_i;
	else if (head_element[0] == '>')
		ast->rdt = e_rdtope_redirect_o;
	else if (head_element[0] == '<')
		ast->rdt = e_rdtope_redirect_i;
	else
		ast->cmd = ft_strdup(head_element);
}
