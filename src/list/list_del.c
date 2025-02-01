#include "list.h"

t_list	*list_del(t_list *list, int	n)
{
    int     i;
    t_list  *neck;
    t_list  *head;

    i = 0;
    head = list;
    if (n == 0)
        list = list->next;
    else
    {
        while (i <= n - 1)
        {
            if (head == NULL)
                return (NULL);
            neck = head;
            head = head->next;
            i++;
        }
        neck->next = head->next;
    }
    free(head->str);
    free(head);
    return (list);
}
