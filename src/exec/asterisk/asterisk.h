#	ifndef ASTERISK_H
#define ASTERISK_H

#include "list.h"

t_str_list  *expand_asterisk(t_str_list *arg);
t_str_list  *parse_and_expand(char *input);
bool        is_asterisk(char *input);

# endif