#ifndef TOM_PARSER_H
#define TOM_PARSER_H

#include "list.h"

t_char_list *pre_lexer(t_char_list **clst);

int search_string_pattern_replace(t_str_list **lst, t_str_list *pattern);

int ope_collector(t_str_list **lexed);

t_str_list *
lexer(char *str);
#endif
