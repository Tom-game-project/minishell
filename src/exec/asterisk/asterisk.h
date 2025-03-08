#	ifndef ASTERISK_H
#define ASTERISK_H

#include "list.h"

t_str_list  *expand_asterisk(t_str_list *arg);
t_str_list  *expand(char *input);

# endif