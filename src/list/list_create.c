#include "list.h"

t_list  *list_create(char *str)
{
    t_list  *list;

    list = (list *)malloc(sizeof(t_str_list));
    if (list == NULL)
        return (NULL);
    list->str = ft_strdup(str);
    list->next = NULL;
    return (list);
}
