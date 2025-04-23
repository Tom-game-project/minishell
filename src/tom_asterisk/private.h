#ifndef PRIVATE_H
#define PRIVATE_H

#include "list.h"
#include <stdbool.h>

/// コンビネーション(n,2)の順列を試す関数
bool comb2_any(
	t_char_list *lst,
       	t_str_list *rule_lst,
       	bool (*f)(t_char_list *str_lst, t_str_list *rule_list)
);

//bool is_same_string(t_char_list *target, t_str_list *rule_lst);

#endif

