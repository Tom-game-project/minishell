#include "parser.h"
#include "libft.h"

//
#include <stdio.h>
//
static char *ctl_extract_operands(char *input);
static char *search_ctl_operater(char *input);
static void	store_head_element(t_ast  *ast, char *head_element);

void	separate_and_store_control_operators(t_ast  *ast, char *input)
{
	char *head_element;

	if (input == NULL)
		return ;
	head_element = search_ctl_operater(input);
	update_input(&input, head_element);
	store_head_element(ast, head_element);
	free(head_element);
	ast->right_ast = allocation_ast();
	separate_and_store_control_operators(ast->right_ast, input);
	return ;
}

static char *search_ctl_operater(char *input)
{
	char *head_element;

	if (input[0] == '"')
		head_element = ft_substr(input, 0, find_chr(input + 1, '"') + 3);
	else if (input[0] == '\'')
		head_element = ft_substr(input, 0, find_chr(input + 1, '\'') + 3);
	else if (input[0] == '(')
		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 3);
	else if (ft_strncmp(input, "&&", 2) == 0)
		head_element = ft_substr(input, 0, 2);
	else if (ft_strncmp(input, "||", 2) == 0)
		head_element = ft_substr(input, 0, 2);
	else
		head_element = ctl_extract_operands(input);
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

static void	store_head_element(t_ast  *ast, char *head_element)
{
	char *tmp;

	tmp = ft_strtrim(head_element, " ");
	if (ft_strncmp(tmp, "&&", 2) == 0)
		ast->ctlope = e_ctlope_and;
	else if (ft_strncmp(tmp, "||", 2) == 0)
		ast->ctlope = e_ctlope_or;
	else
		ast->cmd = ft_strdup(tmp);
	free(tmp);
}
