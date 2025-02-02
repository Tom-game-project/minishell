#ifndef CHAR_LIST_H
#define CHAR_LIST_H

#include "list.h"

t_char_list	*get_raw_ptr(t_char_list **node_p_p, int index);

t_char_list *get_ptr(t_char_list *head, int index);

t_char_list *get_back(t_char_list *node);
#endif
