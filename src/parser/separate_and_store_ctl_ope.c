#include "parser.h"
#include "libft.h"
#include "list.h"

#include <stdio.h>

t_str_list	*store_left_next_input(char **input);
void	store_ctlope_ast(t_ast	**ast, char **input);
t_str_list	*store_right_next_input(char	*input);

static char *ctl_extract_operands(char *input);
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
	char		*head_element;

	next_input = NULL;
	if (**input == '\0')
		return (next_input);
	head_element = search_ctl_operater(trim_isspc(*input));
	update_input(input, head_element);
	str_list_push(&next_input, ft_strdup(head_element));
	free(head_element);
	return (next_input);
}

void	store_ctlope_ast(t_ast	**ast, char **input)
{
	char		*head_element;

	if (**input == '\0')
		return ;
	head_element = search_ctl_operater(trim_isspc(*input));
	update_input(input, head_element);
	if (ft_strncmp(head_element, "&&", 2) == 0)
		(*ast)->ope = e_ope_and;
	else if (ft_strncmp(head_element, "||", 2) == 0)
		(*ast)->ope = e_ope_or;
	free(head_element);
	return ;
}

t_str_list	*store_right_next_input(char	*input)
{
	t_str_list	*next_input;

	if (*input == '\0')
		return (NULL);
	str_list_push(&next_input, ft_strdup(input));
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



// printf("head:%s\n", head_element);
// printf("str:%s\n", next_input->str);
// if (ast->ope == e_ope_or)
// printf("str:||\n");
// else if(ast->ope == e_ope_and)
// printf("str:&&\n");
// else
// printf("str:none\n");


// printf("-------------");