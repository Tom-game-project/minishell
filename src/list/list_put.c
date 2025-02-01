#include "list.h"

void    list_put(t_list *list, int	n, char *str)
{
    int     i;
    t_list  *tmp;
    t_list  *head;

    i = 0;
    head = list;
    if (n == 0)
    {
        list = list_create(str);
        list->next = head;
    }
    else
    {
        while (i <= n - 1)
        {
            if (head == NULL)
                return (NULL);
            head = head->next;
            i++;
        }
        tmp = head;
        head = list_create(str);
        head->next = tmp;
    }
}
