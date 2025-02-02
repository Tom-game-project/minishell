#include "list.h"

t_node  *node_create(char *str)
{
    t_node  *node;

    node = (node *)malloc(sizeof(t_str_node));
    if (node == NULL)
        return (NULL);
    node->str = ft_strdup(str);
    node->next = NULL;
    return (node);
}
