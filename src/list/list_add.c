#include "list.h"

void	*list_add(t_list *list, char *str)
{
    t_list *head;

    head = list;
    while (list->next != NULL)
        *head = head->next;
    head->next = list_create(str);
    return (list);
}