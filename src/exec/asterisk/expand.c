#include "asterisk.h"
#include "list.h"
#include "path.h"
#include "libft.h"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

t_str_list *search_dir_list(char *input);
void	asterisk_parser(t_str_list	**after_parse, char *input);
t_str_list	*expand(t_str_list *after_parse, t_str_list *head);
char *get_path_from_input(char *input);

t_str_list  *parse_and_expand(char *input)
{
	t_str_list  *after_expand;
	t_str_list  *after_parse;
	t_str_list  *head;

	after_parse = NULL;
	asterisk_parser(&after_parse, input);
	head = after_parse;
	after_expand = expand(after_parse, head);
	return (after_expand);
}

void	asterisk_parser(t_str_list	**after_parse, char *input)
{
	int			idx;

	if (*input == '\0')
		return ;
	idx = 0;
	while (*(input + idx) != '/' || *(input + idx) != '\0')
		idx++;
	str_list_push(after_parse, ft_substr(input, 0, idx));
	asterisk_parser(after_parse, input + (idx + 1));
}

t_str_list	*expand(t_str_list *after_parse, t_str_list *head)
{
	t_str_list *after_expand;
	t_str_list *after_expand->head;

	after_expand

	after_expand_head->next = expand(after_parse, head);
	return (after_expand);
}

t_str_list *search_dir_list(char *input)//inputで指定されたpathのディレクトリの内容を取得。
{
	char		*dir_path;
	t_str_list	*dir_list;
	
	if (ft_strnstr(input, "/*", ft_strlen(input)))
	{
		dir_path = get_path_from_input(input);
		dir_list = get_dir_list(dir_path);
	}
	else
		dir_list = get_dir_list(".");
	return (dir_list);
}

char *get_path_from_input(char *input)//inputに含まれるディレクトリpathを抽出する。
{
	size_t	input_len;
	char	*dir_path;

	input_len = ft_strlen(input);
	while (*(input + input_len) != '/')
		input_len--;
	dir_path = ft_substr(input, 0, input_len);
	return (dir_path);
}
