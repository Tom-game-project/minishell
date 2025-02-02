#include "parser.h"

t_char_list split_input(char *input)
{
	t_char_list *list_input;

	surch_operater(&input);

	return (list_input);
}

//閉じられていなかったときのエラーハンドリングを追加
//かっこが閉じられていなかった場合の処理について検討の必要あり

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
