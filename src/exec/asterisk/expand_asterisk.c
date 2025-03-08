#include "asterisk.h"
#include "list.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

t_str_list  *recursive_process(t_str_list *head, int depth);
t_str_list  *join_to_cmd(t_str_list	*after_expand, t_str_list	*arg_cpy);
bool        ft_strncmp_wrap(t_anytype	s1, t_anytype	s2);

t_str_list  *expand_asterisk(t_str_list *arg)
{
	t_str_list  *arg_cpy;
	t_str_list  *after_expand;

	arg_cpy = str_list_clone(arg, ft_strdup);
	after_expand = recursive_process(arg_cpy, 0);
	merge_sort(&after_expand, ft_strncmp_wrap);
	str_list_clear(&arg_cpy, free);
	return (after_expand);
}

t_str_list *recursive_process(t_str_list *head, int depth)
{
	t_str_list *after_expand;
	t_str_list *after_expand_head;

	if (head == NULL)
		return (NULL);
    after_expand = NULL;
	if (is_asterisk(head->ptr.str))
	{
		after_expand = parse_and_expand(head->ptr.str);
		after_expand_head = after_expand;
		while(after_expand_head != NULL)
			after_expand_head = after_expand_head->next;
	}
	else
		str_list_push(&after_expand_head, head->ptr.str);
	after_expand_head = recursive_process(head->next, depth + 1);
	return (after_expand);
}

t_str_list  *join_to_cmd(t_str_list	*after_expand, t_str_list	*arg_cpy)
{
	void_list_insert(&after_expand, 0, arg_cpy->ptr);
	str_list_clear(&arg_cpy, free);
	return (after_expand);
}

bool	ft_strncmp_wrap(t_anytype	s1, t_anytype	s2)
{
	int result;

	result = ft_strncmp(s1.str, s2.str, 1);
	if (result == 0)
		return (true);
	return (false);
}