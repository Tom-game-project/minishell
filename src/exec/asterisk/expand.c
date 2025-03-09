#include "asterisk.h"
#include "list.h"
#include "path.h"
#include "libft.h"
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

t_str_list	*expand(t_str_list *after_parse, t_str_list *head, int depth);
t_str_list *search_dir_list(t_str_list *after_parse, int head);
char *get_path_from_input(t_str_list *after_parse, int head);

t_str_list  *parse_and_expand(char *input)
{
	t_str_list  *after_expand;
	t_str_list  *after_parse;
	t_str_list  *head;

	after_parse = NULL;
	asterisk_parser(&after_parse, input);
	head = after_parse;
	after_expand = expand(after_parse, head, 0);
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

t_str_list	*expand(t_str_list *after_parse, t_str_list *head, int depth)
{
	t_str_list *after_expand;
	t_str_list *after_expand->head;

	after_expand = NULL;
	(void)after_parse;
	(void)head;
	if (!is_asterisk(head->ptr.str))
		head = head->next;
	after_expand_head->next = expand(after_parse, head, depth + 1);
	return (after_expand);
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
	t_str_list	*list_path;
	t_str_list	*after_parse_cpy;
	char		*dir_path;

	after_parse_cpy = str_list_clone(after_parse, ft_strdup);
	list_path = str_list_cut(&after_parse_cpy, head);
	dir_path = str_list_join(list_path, "/");
	str_list_clear(&list_path, free);
	str_list_clear(&after_parse_cpy, free);
	return (dir_path);
}
