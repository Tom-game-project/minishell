#include "parser.h"
#include "libft.h"
#include <stdlib.h>

char *search_operater(char **input)
{
	char    *head_element;

	if (*input[0] == '"')
		head_element = ft_substr(*input, 0, find_chr(*input + 1, '"') + 2);
	else if (*input[0] == '\'')
		head_element = ft_substr(*input, 0, find_chr(*input + 1, '\'') + 2);
	else if (*input[0] == '(')
		head_element = ft_strdup("(");
	else if (*input[0] == ')')
		head_element = ft_strdup(")");
	else if (ft_strncmp(*input, "&&", 2) == 0)
		head_element = ft_strdup("&&");
	else if (ft_strncmp(*input, "||", 2) == 0)//strncmp()に変更してセグフォ保護
		head_element = ft_strdup("||");
	else if (*input[0] == '|')
		head_element = ft_strdup("|");
	else if (*input[0] == ' ')
		head_element = ft_strdup(" ");
	else
		head_element = NULL;
	if (head_element != NULL)
		update_input(input, head_element);
	return (head_element);
}

//閉じられていなかったときのエラーハンドリングを追加
//かっこが閉じられていなかった場合の処理について検討の必要あり
