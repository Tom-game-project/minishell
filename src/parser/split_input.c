#include "parser.h"

t_char_list split_input(char *input)
{
	t_char_list *list_input;

	surch_operater(&input);

	return (list_input);
}

//閉じられていなかったときのエラーハンドリングを追加
//かっこが閉じられていなかった場合の処理について検討の必要あり
char *surch_operater(char **input)
{
	char    *head_element;

	if (*input[0] == "'")
		head_element = ft_substr(*input, 0, strchar(input[i], "'"));
	else if (*input[0] == "'")
		head_element = ft_substr(*input, 0, strchar(input[i], '"'));
	else if (*input[0] == "(")
		head_element = ft_strdup("(");
	else if (*input[0] == ")")
		head_element = ft_strdup(")");
	else if (*input[0] == "&" && *input[1] == "&")
		head_element = ft_strdup("&&");
	else if (*input[0] == "|" && *input[1] == "|")
		head_element = ft_strdup("||");
	else if (*input[0] == "|")
		head_element = ft_strdup("|");
	else if (*input[0] == " ")
		head_element = ft_strdup(" ");
	else
		head_element = NULL;
	if (head_element != NULL)
		update_input(input);
	return (head_element);
}

void	update_input(char **input, char *head_element)
{
	int i;
	char *tmp;

	i = 1;
	if (strcmp(head_element, "&&") == 0
		|| strcmp(head_element, "||") == 0)
		i = 2;
	tmp = ft_substr(*input, i, ft_strlen(*input + i));
	free(*input);
	*input = tmp;
}

//(echo hello | echo "hello&&") || ls -la
