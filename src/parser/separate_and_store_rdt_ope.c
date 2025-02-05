#include "parser.h"
#include "libft.h"

static char *search_rdt_operater(char *input);
static char *rdt_extract_operands(char *input);
static void store_head_element(t_ast  *ast, char *head_element);

void   separate_and_store_redirect_operators(t_ast  *ast, char *input)
{
	char *head_element;

	if (input == NULL)
		return ;
	head_element = search_rdt_operater(input);
	update_input(&input, head_element);
	store_head_element(ast, head_element);
	free(head_element);
	ast->right_ast = allocation_ast();
	separate_and_store_redirect_operators(ast->right_ast, input);
	return ;
}

static char *search_rdt_operater(char *input)
{
	char *head_element;

	if (input[0] == '"')
		head_element = ft_substr(input, 0, find_chr(input + 1, '"') + 2);
	else if (input[0] == '\'')
		head_element = ft_substr(input, 0, find_chr(input + 1, '\'') + 2);
	else if (input[0] == '(')
		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
	else if (input[0] == '|')
		head_element = ft_strdup("|");
	else if (ft_strncmp(input, ">>", 2) == 0)
		head_element = ft_strdup(">>");
	else if (ft_strncmp(input, "<<", 2) == 0)
		head_element = ft_strdup("<<");
	else if (input[0] == '>')
		head_element = ft_strdup(">");
	else if (input[0] == '<')
		head_element = ft_strdup("<");
	else
		head_element = rdt_extract_operands(input);
	return (head_element);
}

static char *rdt_extract_operands(char *input)
{
	size_t	i;
	char	*head_element;

	i = 0;
	while (input[i] != '\0' && is_redirect_operators(input + i) == 0)
		i++;
	head_element = ft_substr(input, 0, i);
	return (head_element);
}

static void store_head_element(t_ast  *ast, char *head_element)
{
	char *tmp;

	tmp = ft_strtrim(head_element, " ");
	if (head_element[0] == '|')
		ast->rdtope = e_rdtope_pipe;
	else if (ft_strncmp(head_element, ">>", 2) == 0)
		ast->rdtope = e_rdtope_heredoc_o;
	else if (ft_strncmp(head_element, "<<", 2) == 0)
		ast->rdtope = e_rdtope_heredoc_i;
	else if (head_element[0] == '>')
		ast->rdtope = e_rdtope_redirect_o;
	else if (head_element[0] == '<')
		ast->rdtope = e_rdtope_redirect_i;
	else
		ast->cmd = ft_strdup(tmp);
}
