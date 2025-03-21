#ifndef PRIVATE_H
#define PRIVATE_H

#include "parser.h"
#include <stdbool.h>

t_ast *init_ast();

t_operator str2ope(char *str);

bool startswith_open_paren(char *str);

bool is_rdt_string(char *str);

bool is_ope_string(char *str);

int remove_ifs(t_str_list **lst);

#endif
