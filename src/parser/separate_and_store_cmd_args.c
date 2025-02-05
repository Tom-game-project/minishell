
#include "parser.h"
#include "list.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static char *search_delimiter(char *input);
static char *spc_extract_operands(char *input);
static void	store_head_element(t_ast	*ast, char *input);

void   separate_and_store_cmd_args(t_ast *ast, char *input)
{
	store_head_element(ast, input);
	return ;
}

static char *search_delimiter(char *input)
{
	char *head_element;

	if (input[0] == '"')
		head_element = ft_substr(input, 0, find_chr(input + 1, '"') + 2);
	else if (input[0] == '\'')
		head_element = ft_substr(input, 0, find_chr(input + 1, '\'') + 2);
	else if (input[0] == '(')
		head_element = ft_substr(input, 0, find_chr(input + 1, ')') + 2);
	else
		head_element = spc_extract_operands(input);
	if (*head_element == '\0')
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
    return ft_substr(input, start, len);;
	return (head_element);
}

static void	store_head_element(t_ast	*ast, char *input)
{
	char *tmp;
	char *head_element;

	if (input == NULL)
		return ;
	tmp = search_delimiter(input);
	head_element = ft_strtrim(tmp, " "); //改行とタブは考慮されない
	update_input(&input, head_element);
	str_list_push(&ast->arg, head_element);
	store_head_element(ast, input);
}

//---------------------------------------------------------------------------
// static void	store_head_element(t_ast  *ast, char **cmd_and_argv);

// void   separate_and_store_cmd_args(t_ast *ast, char *input)
// {
// 	char    **cmd_and_argv;

// 	if (is_string(input) == true)
// 		return ;
// 	cmd_and_argv = ft_split(input, ' ');
// 	if (cmd_and_argv == NULL)
// 		exit(EXIT_FAILURE);
// 	store_head_element(ast, cmd_and_argv);
// }

// static void	store_head_element(t_ast  *ast, char **cmd_and_argv)
// {
// 	int     i;

// 	i = 0;
// 	while (cmd_and_argv[i] != NULL)
// 		i++;
// 	ast->argv = (char **)malloc(sizeof(char *) * i);
// 	if (ast->argv == NULL)
// 		exit(EXIT_FAILURE);
// 	ast->cmd = ft_strdup(cmd_and_argv[0]);
// 	free(cmd_and_argv[0]);
// 	i = 0;
// 	while (cmd_and_argv[i] != NULL)
// 	{
// 		ast->argv[i - 1] = ft_strdup(cmd_and_argv[i]);
// 		free(cmd_and_argv[i]);
// 		i++;
// 	}
// 	ast->argv[i - 1] = NULL;
// 	free(cmd_and_argv);
// }
