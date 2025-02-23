#ifndef CHAR_LIST_H
#define CHAR_LIST_H

#include "list.h"

t_char_list *char_list_get_ptr(t_char_list *head, int index);

//t_char_list *get_back(t_char_list *node);
t_char_list *char_list_get_back(t_char_list *node);
#endif
