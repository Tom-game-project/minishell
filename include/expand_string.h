#ifndef EXPAND_STRING_H
#define EXPAND_STRING_H

#include "list.h"
#include "dict.h"

t_void_list	*expand_string2list2(char *str, t_str_dict *env_dicts);

char *heredoc_expand_string(char *str, t_str_dict *env_dicts);

int heredoc_expand_string_via_fd(int fd, t_str_dict *env_dict);
#endif
