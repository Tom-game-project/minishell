#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

// static char	*extract_operands(char *input);
// static bool	is_operater(char *input);

// char *search_operater(char **input)
// {
// 	char    *head_element;

// 	if (*input[0] == '|')//リダイレクトと理論演算子で分割しようかな
// 		head_element = ft_strdup("|");
// 	else if (ft_strncmp(*input, ">>", 2) == 0)
// 		head_element = ft_strdup(">>");
// 	else if (ft_strncmp(*input, "<<", 2) == 0)
// 		head_element = ft_strdup("<<");
// 	else if (*input[0] == '>')
// 		head_element = ft_strdup(">");
// 	else if (*input[0] == '<')
// 		head_element = ft_strdup("<");
// 	else if (*input[0] == ' ')
// 		head_element = ft_strdup(" ");
// 	else
// 		head_element = extract_operands(*input);
// 	update_input(input, head_element);
// 	return (head_element);
// }

// static char *extract_operands(char *input)
// {
// 	size_t	i;
// 	char	*head_element;

// 	i = 0;
// 	while (input[i] != '\0' && is_operater(input + i) == false)
// 		i++;
// 	head_element = ft_substr(input, 0, i);
// 	return (head_element);
// }

// static bool is_operater(char *input)
// {
// 	if (input[0] == '"')
// 		return (true);
// 	else if (input[0] == '\'')
// 		return (true);
// 	else if (input[0] == '(')
// 		return (true);
// 	else if (input[0] == ')')
// 		return (true);
// 	else if (ft_strncmp(input, "&&", 2) == 0)
// 		return (true);
// 	else if (ft_strncmp(input, "||", 2) == 0)
// 		return (true);
// 	else if (input[0] == '|')//リダイレクトと理論演算子で分割しようかな
// 		return (true);
// 	else if (ft_strncmp(input, ">>", 2) == 0)
// 		return (true);
// 	else if (ft_strncmp(input, "<<", 2) == 0)
// 		return (true);
// 	else if (input[0] == '>')
// 		return (true);
// 	else if (input[0] == '<')
// 		return (true);
// 	else if (input[0] == ' ')
// 		return (true);
// 	return (false);
// }

//閉じられていなかったときのエラーハンドリングを追加
//かっこが閉じられていなかった場合の処理について検討の必要あり
