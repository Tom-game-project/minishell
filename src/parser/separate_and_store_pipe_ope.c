#include "parser.h"
#include "libft.h"
#include <stdio.h>

static t_str_list	*store_left_next_input(char **input);
static void	store_pipe_ast(t_ast	**ast, char **input);
static t_str_list	*store_right_next_input(char	*input);
static char *search_pipe_operater(char *input);

t_str_list	*separate_and_store_pipe_operators(t_ast  *ast, char **input)
{
	t_str_list	*next_input;

	next_input = store_left_next_input(input);
	store_pipe_ast(&ast, input);
	next_input->next = store_right_next_input(*input);
	return (next_input);
}

static t_str_list	*store_left_next_input(char **input)
{
	t_str_list	*next_input;
	char		*head_element;
	char		*after_trim;

	next_input = NULL;
	if (ft_strncmp(*input, "|", 1) == 0)
	{
		str_list_push(&next_input, NULL);
		return (next_input);
	}
	if (**input == '\0')
		return (next_input);
	after_trim = trim_isspc(*input);
	head_element = search_pipe_operater(after_trim);
	update_input(input, head_element);
	str_list_push(&next_input, trim_isspc(head_element));
	free(after_trim);
	free(head_element);
	return (next_input);
}

static void	store_pipe_ast(t_ast	**ast, char **input)
{
	char	*after_trim;
	char	*head_element;

	if (**input == '\0')
		return ;
	after_trim = trim_isspc(*input);
	head_element = search_pipe_operater(after_trim);
	update_input(input, head_element);
	if (*head_element == '|')
		(*ast)->ope = e_ope_pipe;
	free(after_trim);
	free(head_element);
	return ;
}

static t_str_list	*store_right_next_input(char	*input)
{
	char *after_trim;
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

static char *search_pipe_operater(char *input)
{
	char *head_element;

	if (*input == '|')
		head_element = ft_strdup("|");
	else
		head_element = ft_substr(input, 0, str_pipe_len(input));
	return (head_element);
}
