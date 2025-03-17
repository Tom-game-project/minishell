#ifndef TOM_PARSER_H
#define TOM_PARSER_H

#include "list.h"
#include "parser.h"

t_char_list *pre_lexer(t_char_list **clst);

int search_string_pattern_replace(t_str_list **lst, t_str_list *pattern);

int ope_collector(t_str_list **lexed);

t_str_list *
lexer(char *str);

t_parse_result	tom_parser_lexed(t_ast **ast, t_str_list *input);

t_ast *init_ast();

t_parse_result	tom_parser(char *input, t_ast **ast);

int split_by_ifs(t_str_list **lst, void (*f)(void *));

#endif
