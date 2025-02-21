
#include "parser.h"
#include "list.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static char *spc_extract_operands(char *input);
static void	store_head_element(t_ast	*ast, char **input);

void   separate_and_store_cmd_args(t_ast *ast, char	**input)
{
	char	*after_trim;
	char	*paren_input;

	if (input == NULL)
		return ;
	if (**input == '(')
	{
		after_trim = trim_isspc(*input);
		paren_input = ft_substr(after_trim, 1, ft_strlen(after_trim) - 2);
		ast->ope = e_ope_paren;
		parser(&ast->left_ast, paren_input);
		free(after_trim);
		free(paren_input);
	}
	else
		store_head_element(ast, input);
	return ;
}

char *search_delimiter(char *input)
{
	char *head_element;

	if (input[0] == '"')
		head_element = ft_substr(input, 0, find_syntax(input));
	else if (input[0] == '\'')
		head_element = ft_substr(input, 0, find_syntax(input));
	else if (ft_strncmp(input,"$(", 2) == 0)
		head_element = ft_substr(input, 0, find_syntax(input));
	else if (input[0] == '(')
		head_element = ft_substr(input, 0, find_syntax(input));
	else
		head_element = spc_extract_operands(input);
	if (head_element[0] == '\0')
	{
		free(head_element);
		return (NULL);
	}
	return (head_element);
}

static char *spc_extract_operands(char *input)//spcの前に文字列文字が来たらそれで区切りたい
{
	size_t	len;
	size_t	start;
	char	*head_element;

    start = 0;
    while (input[start] != '\0' && ft_isspace(input[start]))
        start++;
    len = start;
    while (input[len] != '\0' && !ft_isspace(input[len]) && !is_string(input + len))
        len++;
    len = len - start;
    head_element = ft_substr(input, start, len);
	return (head_element);
}

static void	store_head_element(t_ast	*ast, char **input)
{
	char *head_element;
	char *after_trim;

	after_trim = trim_isspc(*input);
	if (*after_trim == '\0')
	{
		free(after_trim);
		return ;
	}
	head_element = search_delimiter(after_trim);
	update_input(input, head_element);
	str_list_push(&ast->arg, ft_strdup(head_element));
	free(after_trim);
	free(head_element);
	store_head_element(ast, input);
}
