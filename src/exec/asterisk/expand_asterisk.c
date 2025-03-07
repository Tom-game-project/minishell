#include "expand_string.h"
#include "list.h"
#include "parser.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

bool	is_asterisk(char *input);
t_str_list *recursive_process(t_str_list *head, int depth);
t_str_list  *join_to_cmd(t_str_list	*after_expand, t_str_list	*arg_cpy);

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
	if (is_asterisk(head->ptr.str))
	{
		after_expand = expand(head->ptr.str);
		after_expand_head = after_expand;
		free(str_list_pop(&head, 0));
		while(after_expand_head != NULL)
			after_expand_head = after_expand_head->next;
		after_expand->next = head->next;
	}
	head->next = recursive_process(head->next, depth + 1);
	return (head);
}

bool	is_asterisk(char *input)
{
	int idx;

	idx = 0;
	while (*(input + idx) != '\0')
	{
		if (*(input + idx) == '*')
			return (true);
		update_idx(input + idx, idx);
	}
	return (false);
}

t_str_list  *expand(char *input)
{

}

t_str_list  *join_to_cmd(t_str_list	*after_expand, t_str_list	*arg_cpy)
{
	void_list_insert(&after_expand, 0, arg_cpy->ptr);
	str_list_clear(&arg_cpy, free);
	return (after_expand);
}

bool	ft_strncmp_wrap(t_str_list	*s1, t_str_list	*s2)
{

	return (false);
}