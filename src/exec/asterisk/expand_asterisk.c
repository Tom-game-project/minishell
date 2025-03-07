#include "expand_string.h"
#include "list.h"
#include "parser.h"
#include "libft.h"

t_str_list  *expand_asterisk(t_str_list *arg)
{
    t_str_list  *arg_cpy
    t_str_list  *after_expand;

    arg_cpy = str_list_clone(arg->next, ft_strdup);
    after_expand = recursive_process(arg_cpy, 0);
    str_list_sort(after_expand);
    join_to_cmd(after_expand, arg_cpy);
    return (after_expand);
}

t_str_list *recursive_process(t_str_list *head, int depth)
{
    t_str_list *after_expand;

    if (head == NULL)
        return (NULL);
    if (is_asterisk(head->ptr.str))
    {
        after_expand = expand(head->ptr.str);
    }
    head->next = recursive_process(head->next, depth + 1);
    return (head);
}

t_str_list  *expand(char *input)
{

}