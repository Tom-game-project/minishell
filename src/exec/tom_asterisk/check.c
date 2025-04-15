#include <stdbool.h>
#include "list.h"
#include "libft.h"
#include "strtools.h"
#include "private.h"

bool is_same_string(t_char_list *target, t_str_list *rule_lst);

static bool
pattern_length_one(t_char_list *target, t_str_list *rule_lst)
{
	char *str;
	bool r;
	if (ft_streq(str_list_get_elem(rule_lst, 0), "*"))
		return (true);
	else
	{
		str = char_list_to_str(target);
		r = ft_streq(str_list_get_elem(rule_lst, 0), str);
		free(str);
		return (r);
	}
}

static bool
pattern_head_junk(t_char_list *target, t_str_list *rule_lst, char *head_rule)
{
	t_char_list *tmp;
	t_str_list *rule_tmp;
	bool r;

	if (char_list_startswith(target, head_rule))
	{
		tmp = char_list_cut(&target, ft_strlen(head_rule) - 1); // tmpにheadが入る
		rule_tmp = str_list_cut(&rule_lst, 0);
		r = is_same_string(target, rule_lst);
		void_list_concat(&tmp, target);
		void_list_concat(&rule_tmp, rule_lst);
		rule_lst = rule_tmp;
		target = tmp;
		return (r);
	}
	else
		return (false);
}

static bool pattern_junk_tail(t_char_list *target, t_str_list *rule_lst, char *tail_rule)
{	
	t_char_list *tmp;
	t_str_list *rule_tmp;
	bool r;

	if (char_list_endswith(target, tail_rule))
	{
		tmp = char_list_cut(
			&target,
			char_list_len(target) - ft_strlen(tail_rule) - 1); // targetにtailが残る
		rule_tmp = str_list_cut(&rule_lst, str_list_len(rule_lst) - 1 - 1); // 最後のindexの一個手前
		r = is_same_string(tmp, rule_tmp);
		void_list_concat(&tmp, target);
		void_list_concat(&rule_tmp, rule_lst);
		rule_lst = rule_tmp;
		target = tmp;
		return (r);
	}
	else
		return (false);
}

static bool pattern_junk_middle_junk(t_char_list *target, t_str_list *rule_lst)
{	
	t_str_list *head_rule_tmp;
	t_str_list *middle_rule_tmp;
	bool r;

	head_rule_tmp = str_list_cut(&rule_lst, 0);
	middle_rule_tmp = str_list_cut(&rule_lst, str_list_len(rule_lst) - 1);
	r = comb2_any(target, middle_rule_tmp, is_same_string);
	void_list_concat(&head_rule_tmp, middle_rule_tmp);
	void_list_concat(&head_rule_tmp, rule_lst);
	return (r);
}

/// "a*b*c" === "aacgggfafdbddddc" -> true
///              a---------b----c
/// "*.c" === "hello.c.c" -> true
///            -------.c
///
/// 気をつけるケース
/// *helloworld*.c
/// hellohelloworld123.c.c
/// (hello)helloworld(123.c).c
/// 
/// *hello*world*
///  -------------- ... A
/// world hello -> false
/// 
///
/// ```
/// *.c
/// (a.c).c
/// ```
/// ```
/// hello*lll*world ... 1
/// *hello*lll*world ... 2
/// hello*lll*world* ... 3
/// *hello*lll*world* ... 4
/// ```
///
/// 再帰的に探索する
bool is_same_string(t_char_list *target, t_str_list *rule_lst)
{
	char *head_rule;
	char *tail_rule;

	if (str_list_len(rule_lst) == 0)
		return (false);
	else if (str_list_len(rule_lst) == 1)
		return (pattern_length_one(target, rule_lst));
	head_rule = str_list_get_elem(rule_lst, 0);
	tail_rule = str_list_get_elem(rule_lst, str_list_len(rule_lst) - 1);
	if (!ft_streq(head_rule, "*"))
		return (pattern_head_junk(target, rule_lst, head_rule));
	if (!ft_streq(tail_rule, "*"))
		return (pattern_junk_tail(target, rule_lst, tail_rule));
	return (pattern_junk_middle_junk(target, rule_lst));
}
