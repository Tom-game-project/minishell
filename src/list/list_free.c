#include "list.h"

void    list_free(t_list	*list)
{
    free(list->str);
    if (list->next == NULL)
        return ;
    list_free(list->next);
    return ;
}
