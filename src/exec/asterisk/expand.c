#include "asterisk.h"
#include "list.h"
#include "path.h"
#include "libft.h"
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

t_str_list	*recursive_for_expand(t_str_list *head, int depth);
t_str_list *search_dir_list(t_str_list *after_parse, int head);
char *get_path_from_input(t_str_list *after_parse, int head);

t_str_list  *parse_and_expand(char *input)
{
	t_str_list  *after_expand;
	t_str_list  *after_parse;

	after_parse = NULL;
	asterisk_parser(&after_parse, input);
	after_expand = recursive_for_expand(after_parse, 0);
	return (after_expand);
}

void	asterisk_parser(t_str_list	**after_parse, char *input)
{
	int			idx;

	if (*input == '\0')
		return ;
	idx = 0;
	while (*(input + idx) != '/' && *(input + idx) != '\0')
		idx++;
	str_list_push(after_parse, ft_substr(input, 0, idx));
	if (*(input + idx) == '/')
		idx++;
	asterisk_parser(after_parse, input + idx);
}

t_str_list	*recursive_for_expand(t_str_list *after_parse, int depth)
{
	t_str_list *after_expand;
	t_str_list *after_expand_head;

	after_expand = NULL;
	if (is_asterisk(after_parse->ptr.str))
	{
		after_expand = expand(after_parse->ptr.str, depth);
		after_expand_head = after_expand;
		while (after_expand_head != NULL)
			after_expand_head = after_expand_head->next;
	}
	else
		str_list_push(&after_expand, after_parse->ptr.str);
	after_expand_head = recursive_for_expand(after_parse->next, depth + 1);
	return (after_expand);
}

t_str_list	*expand(t_str_list *after_parse, char *input, int depth)
{
	t_str_list *dir_list;

	dir_list = search_dir_list(after_parse, depth);
	
}

t_str_list *search_dir_list(t_str_list *after_parse, int head)//inputで指定されたpathのディレクトリの内容を取得。
{
	char		*dir_path;
	t_str_list	*dir_list;
	
	if (after_parse->next != NULL)
	{
		dir_path = get_path_from_input(after_parse, head);
		dir_list = get_dir_list(dir_path);
	}
	else
		dir_list = get_dir_list(".");
	return (dir_list);
}

char *get_path_from_input(t_str_list *after_parse, int head)//inputに含まれるディレクトリpathを抽出する。
{
	t_str_list	*after_parse_cpy;
	char		*dir_path;

	after_parse_cpy = str_list_clone(after_parse, ft_strdup);
	str_list_cut(&after_parse_cpy, head);
	dir_path = str_list_join(after_parse_cpy, "/");
	str_list_clear(&after_parse_cpy, free);
	return (dir_path);
}
