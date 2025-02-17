#include "parser.h"
#include "libft.h"
#include <stdio.h>

static t_str_list	*store_left_next_input(char **input);
static void		store_rdtope_ast(t_ast	**ast, char **input);
static t_str_list	*store_right_next_input(char	*input);
static char	*search_rdt_operater(char *input);
static void	store_rdtarg(t_ast *ast, char **input);


t_str_list	*separate_and_store_redirect_operators(t_ast  *ast, char **input)
{
	t_str_list	*next_input;

	next_input = store_left_next_input(input);
	store_rdtope_ast(&ast, input);
	if (ast->ope == e_ope_redirect_i
		|| ast->ope == e_ope_redirect_o
		|| ast->ope == e_ope_heredoc_i
		|| ast->ope == e_ope_heredoc_o)
		store_rdtarg(ast, input);
	next_input->next = store_right_next_input(*input);
	return (next_input);
}

t_str_list	*store_left_next_input(char **input)
{
	t_str_list	*next_input;
	char		*head_element;

	next_input = NULL;
	if (is_redirect_operators(*input))
	{
		str_list_push(&next_input, NULL);
		return (next_input);
	}
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
	char	*after_trim;
	char	*head_element;

	if (**input == '\0')
		return ;
	after_trim = trim_isspc(*input);
	head_element = search_rdt_operater(after_trim);
	free(after_trim);
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
	char *tmp;
	t_str_list	*next_input;

	tmp = trim_isspc(input);
	if (*tmp == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	next_input = NULL;
	str_list_push(&next_input, tmp);
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

void	store_rdtarg(t_ast *ast, char **input)
{
	char *head_element;

	head_element = search_delimiter(trim_isspc(*input));
	if (head_element == NULL)
		return ;
	str_list_push(&ast->arg, head_element);
	update_input(input, head_element);
}
