#include "list.h"

void	node_add(t_node **node, char *str)
{
    t_node*head;

    head = node;
    while (node->next != NULL)
        *head = head->next;
    head->next = node_create(str);
}