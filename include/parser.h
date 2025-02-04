#ifndef PARSER_H
#define PARSER_H
#include "list.h"
#include "dict.h"

t_str_list *expand_string(char *str, t_str_dict *env_dicts);
#endif
