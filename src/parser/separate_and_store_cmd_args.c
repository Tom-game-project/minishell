
#include "parser.h"
#include "list.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static char *search_delimiter(char *input);
static char *spc_extract_operands(char *input);
static void	store_head_element(t_ast	*ast, char *input);

void   separate_and_store_cmd_args(t_ast *ast, char **input)
{
	char *tmp;

	if (*input == NULL)
		return ;
	if (**input == '(')
	{
		tmp = ft_substr(*input, 1, ft_strlen(*input) - 1);
		parser(&ast, tmp);
	}
	else
		store_head_element(ast, *input);
	return ;
}

static char *search_delimiter(char *input)
{
	char *head_element;

	if (input[0] == '"')
		head_element = ft_substr(input, 0, find_chr(input + 1, '"') + 2);
	else if (input[0] == '\'')
		head_element = ft_substr(input, 0, find_chr(input + 2, '\'') + 2);
	else if (ft_strncmp(input,"$(", 2) == 0)
		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
	else if (input[0] == '(')
		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
	else
		head_element = spc_extract_operands(input);
	if (head_element[0] == '\0')
		return (NULL);
	return (head_element);
}

static char *spc_extract_operands(char *input)
{
	size_t	len;
	size_t	start;
	char	*head_element;

    start = 0;
    while (input[start] != '\0' && ft_isspace(input[start]))
        start++;
    len = start;
    while (input[len] != '\0' && !ft_isspace(input[len]))
        len++;
    len = len - start;
    head_element = ft_substr(input, start, len);
	return (head_element);
}

static void	store_head_element(t_ast	*ast, char *input)
{
	char *head_element;

	head_element = search_delimiter(trim_isspc(input));
	if (head_element == NULL)
		return ;
	update_input(&input, head_element);
	str_list_push(&ast->arg, head_element);
	store_head_element(ast, input);
}
