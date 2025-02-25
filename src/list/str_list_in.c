#include "list.h"
#include "strtools.h"

#include <stdbool.h>
#include <stdlib.h>


bool str_list_in(char *str, t_str_list *lst)
{
	return (str_list_search_node(lst, ft_streq, str) != NULL);
}
