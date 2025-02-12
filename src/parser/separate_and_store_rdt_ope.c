#include "parser.h"
#include "libft.h"

#include <stdio.h>

static t_str_list	*store_left_next_input(char **input);
static void		store_rdtope_ast(t_ast	**ast, char **input);
static t_str_list	*store_right_next_input(char	*input);
static char	*search_rdt_operater(char *input);

t_str_list	*separate_and_store_redirect_operators(t_ast  *ast, char **input)
{
	t_str_list	*next_input;

	next_input = store_left_next_input(input);
	store_rdtope_ast(&ast, input);
	next_input->next = store_right_next_input(*input);
	return (next_input);
}

t_str_list	*store_left_next_input(char **input)
{
	t_str_list	*next_input;
	char		*head_element;

	next_input = NULL;
	if (**input == '\0')
		return (next_input);
	head_element = search_rdt_operater(trim_isspc(*input));
	update_input(input, head_element);
	str_list_push(&next_input, trim_isspc(head_element));
	free(head_element);
	return (next_input);
}

void	store_rdtope_ast(t_ast	**ast, char **input)
{
	char		*head_element;

	if (**input == '\0')
		return ;
	head_element = search_rdt_operater(trim_isspc(*input));
	update_input(input, head_element);
	if (ft_strncmp(head_element, "<<", 2) == 0)
		(*ast)->ope = e_ope_heredoc_i;
	else if (ft_strncmp(head_element, ">>", 2) == 0)
		(*ast)->ope = e_ope_heredoc_o;
	else if (*head_element == '<')
		(*ast)->ope = e_ope_redirect_i;
	else if (*head_element == '>')
		(*ast)->ope = e_ope_redirect_o;
	else if (*head_element == '|')
		(*ast)->ope = e_ope_pipe;
	free(head_element);
	return ;
}

t_str_list	*store_right_next_input(char	*input)
{
	t_str_list	*next_input;

	if (*input == '\0')
		return (NULL);
	next_input = NULL;
	str_list_push(&next_input, trim_isspc(input));
	return (next_input);
}

static char *search_rdt_operater(char *input)
{
	char *head_element;

	if (ft_strncmp(input, "<<", 2) == 0)
		head_element = ft_strdup("<<");
	else if (ft_strncmp(input, ">>", 2) == 0)
		head_element = ft_strdup(">>");
	else if (*input == '>')
		head_element = ft_strdup(">");
	else if (*input == '<')
		head_element = ft_strdup("<");
	else if (*input == '|')
		head_element = ft_strdup("|");
	else
		head_element = ft_substr(input, 0, str_rdt_len(input));
	return (head_element);
}

// static char *search_rdt_operater(char *input);
// static char *rdt_extract_operands(char *input);
// static void	store_head_element(t_ast  *ast, t_str_list **next_input, char *head_element);

// t_str_list	*separate_and_store_redirect_operators(t_ast  *ast, char **input)
// {
// 	t_str_list	*next_input;
// 	char *head_element;

// 	next_input = NULL;
// 	if (**input == '\0')
// 		return (next_input);
// 	head_element = search_rdt_operater(trim_isspc(*input));
// 	if (head_element == NULL)
// 		return (next_input);
// 	update_input(input, head_element);
// 	store_head_element(ast, &next_input, head_element);
// 	free(head_element);
// 	next_input->next = separate_and_store_redirect_operators(ast, input);
// 	return (next_input);
// }

// static char *search_rdt_operater(char *input)
// {
// 	char *head_element;

// 	if (input[0] == '"')
// 		head_element = ft_substr(input, 0, find_chr(input + 1, '"') + 2);
// 	else if (input[0] == '\'')
// 		head_element = ft_substr(input, 0, find_chr(input + 1, '\'') + 2);
// 	else if (ft_strncmp(input,"$(", 2) == 0)
// 		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
// 	else if (input[0] == '(')
// 		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
// 	else if (ft_strncmp(input, ">>", 2) == 0)
// 		head_element = ft_substr(input, 0, 2);
// 	else if (ft_strncmp(input, "<<", 2) == 0)
// 		head_element = ft_substr(input, 0, 2);
// 	else if (input[0] == '>')
// 		head_element = ft_substr(input, 0, 1);
// 	else if (input[0] == '<')
// 		head_element = ft_substr(input, 0, 1);
// 	else
// 		head_element = rdt_extract_operands(input);
// 	if (*head_element == '\0')
// 		return (NULL);
// 	return (head_element);
// }

// static char *rdt_extract_operands(char *input)
// {
// 	size_t	i;
// 	char	*head_element;

// 	i = 0;
// 	while (input[i] != '\0' && is_redirect_operators(input + i) == false)
// 		i++;
// 	head_element = ft_substr(input, 0, i);
// 	return (head_element);
// }

// static void	store_head_element(t_ast  *ast, t_str_list **next_input, char *head_element)
// {
// 	if (head_element[0] == '|')
// 		ast->ope = e_ope_pipe;
// 	else if (ft_strncmp(head_element, ">>", 2) == 0)
// 		ast->ope = e_ope_heredoc_o;
// 	else if (ft_strncmp(head_element, "<<", 2) == 0)
// 		ast->ope = e_ope_heredoc_i;
// 	else if (head_element[0] == '>')
// 		ast->ope = e_ope_redirect_o;
// 	else if (head_element[0] == '<')
// 		ast->ope = e_ope_redirect_i;
// 	else
// 		str_list_push(next_input, ft_strdup(head_element));
// }
