#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "list.h"
 //#include "test_tools.h"
#include "path.h"
#include "libft.h"
#include "test_tools.h"
#include "strtools.h"

static bool is_slash(char *c)
{
	return (*c == '/');
}

static bool endwith_srash(char *str)
{
	int len;

	len = ft_strlen(str);
	return (str[len - 1] == '/');
}

static bool is_asterisk_char(char *c)
{
	return (*c == '*');
}

/// ルールをフォマットに従わせる関数
///
/// 返却されるpointerはfreeされる必要があります
///
///
/// TODO: 重複した`**` などを`*`にしたりとか
/// `/`を取り除いたりとか
char *
gen_formatted_asterisk_rule(char *raw_rule)
{
	char *rstr;
	size_t len;

	len = ft_strlen(raw_rule);
	if (endwith_srash(raw_rule))
	{
		rstr = ft_substr(raw_rule, 0, len - 1);
	}
	else
	{
		rstr = ft_strdup(raw_rule);
	}
	return (rstr);
}

/// pathを分解する関数
t_str_list *split_path(char *path)
{
	t_char_list *char_lst;
	t_str_list *str_lst;
	int index;

	char_lst = NULL;
	str_lst = NULL;
	char_list_push_str(&char_lst, path);
	index = char_list_search_index(char_lst, is_slash);
	while(index != -1)
	{
		t_char_list *group_char_lst;
		group_char_lst = char_list_cut(&char_lst, index);
		str_list_push(&str_lst, char_list_to_str(group_char_lst));
		index = char_list_search_index(char_lst, is_slash);
		char_list_clear(&group_char_lst);
	}
	if (char_list_len(char_lst) != 0)
	{
		str_list_push(&str_lst, char_list_to_str(char_lst));
	}
	char_list_clear(&char_lst);
	return (str_lst);
}

t_str_list *
rule_to_lst(char *rule_str)
{
	t_char_list *c_lst;
	t_char_list *group;
	t_str_list *rlst;
	int index;

	c_lst = NULL;
	rlst = NULL;
	char_list_push_str(&c_lst, rule_str);
	index = char_list_search_index(c_lst, is_asterisk_char);
	while (index != -1)
	{
		group = char_list_cut(&c_lst, index - 1);
		if (char_list_len(group) != 0)
			str_list_push(&rlst, char_list_to_str(group));
		char_list_pop(&c_lst, 0);
		str_list_push(&rlst, ft_strdup("*"));
		char_list_clear(&group);
		index = char_list_search_index(c_lst, is_asterisk_char);
	}
	if (char_list_len(c_lst) != 0)
		str_list_push(&rlst, char_list_to_str(c_lst));
	char_list_clear(&c_lst);
	return (rlst);
}

static bool slice_comb2_any(
	t_char_list *lst,

       	t_str_list *rule_lst,
       	bool (*f)(t_char_list *str_lst, t_str_list *rule_list),
	int j
)
{
	bool b;
	t_str_list *tmp;

	tmp =  char_list_cut(&lst, j);
	b = f(tmp, rule_lst);
	void_list_concat(&tmp, lst);
	return (b);
}

bool comb2_any(
	t_char_list *lst,
       	t_str_list *rule_lst,
       	bool (*f)(t_char_list *str_lst, t_str_list *rule_list)
)
{
	int len;
	int i;
	int j;

	len = char_list_len(lst);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < char_list_len(lst))
		{
			if (slice_comb2_any(lst, rule_lst, f, j))
				return (true);
			j += 1;
		}
		lst = lst->next;
		i += 1;
	}
	return (false);
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
bool is_same_string(t_char_list *target, t_str_list *rule_lst)
{
	char *head_rule;
	char *tail_rule;

	if (str_list_len(rule_lst) == 0)
	{
		return (false);
	}
	else if (str_list_len(rule_lst) == 1)
	{
		if (ft_streq(str_list_get_elem(rule_lst, 0), "*"))
		{
			return (true);
		}
		else
		{
			char *str;
			bool r;

			str = char_list_to_str(target);
			r = ft_streq(str_list_get_elem(rule_lst, 0), str);
			free(str);
			return (r);
		}
	}

	head_rule = str_list_get_elem(rule_lst, 0);
	tail_rule = str_list_get_elem(rule_lst, str_list_len(rule_lst) - 1);
	if (!ft_streq(head_rule,"*"))
	{
		t_char_list *tmp;
		t_str_list *rule_tmp;
		bool r;
		// startswith head_rule
		if (char_list_startswith(target, head_rule))
		{
			tmp = char_list_cut(&target, ft_strlen(head_rule) - 1); // tmpにheadが入る
			rule_tmp = str_list_cut(&rule_lst, 0);
			/// vvv ルールと,targetをそれぞれカットする
			r = is_same_string(target, rule_lst);
			/// ^^^
			void_list_concat(&tmp, target);
			void_list_concat(&rule_tmp, rule_lst);
			rule_lst = rule_tmp;
			target = tmp;
			return (r);
		}
		else
			return (false);
	}
	if (!ft_streq(tail_rule,"*"))
	{
		t_char_list *tmp;
		t_str_list *rule_tmp;
		bool r;
		// endswith tail_rule
		if (char_list_endswith(target, tail_rule))
		{
			tmp = char_list_cut(
				&target,
			       	char_list_len(target) - ft_strlen(tail_rule) - 1); // targetにtailが残る
			// char_list_print(tmp);
			rule_tmp = str_list_cut(&rule_lst, str_list_len(rule_lst) - 1 - 1); // 最後のindexの一個手前
			//str_list_print(rule_tmp);
			/// vvv ルールと,targetをそれぞれカットする
			r = is_same_string(tmp, rule_tmp);
			/// ^^^
			void_list_concat(&tmp, target);
			void_list_concat(&rule_tmp, rule_lst);
			rule_lst = rule_tmp;
			target = tmp;
			return (r);
		}
		else
			return (false);
	}
	if (ft_streq(head_rule,"*") && ft_streq(tail_rule,"*"))
	{
		t_str_list *head_rule_tmp;
		t_str_list *middle_rule_tmp;
		bool r;

		head_rule_tmp = str_list_cut(&rule_lst, 0);
		middle_rule_tmp = str_list_cut(&rule_lst, str_list_len(rule_lst) - 1);
		
		/// vvv ruleをカットする
		r = comb2_any(target, middle_rule_tmp, is_same_string);
		/// ^^^
		void_list_concat(&head_rule_tmp, middle_rule_tmp);
		void_list_concat(&head_rule_tmp, rule_lst);
		return (r);
	}
	return (true);
}

bool is_same_string_wrap(t_anytype a, t_anytype b)
{
	t_char_list *c_lst;
	t_str_list *rule_lst;
	bool r;

	c_lst = NULL;
	
	char_list_push_str(&c_lst, a.str);
	rule_lst = rule_to_lst(b.str);
	r = is_same_string(c_lst, rule_lst);
	char_list_clear(&c_lst);
	return (r);
}

t_str_list *
get_all_file_and_path(t_str_list **node, char *rule_str)
{
	t_anytype rule_str_anytype;

	rule_str_anytype.str = rule_str;
	return (void_list_filter2(
		node,
	       	is_same_string_wrap,
	       	rule_str_anytype
	));
}

t_str_list *
get_all_path(char *root, t_str_list **splited_path)
{
	t_str_list *rlist;
	t_str_list *current_files;
	t_str_list *filtered;
	char *fmted_str;
	char *joined_path;

	rlist = NULL;
	if (str_list_len(*splited_path) == 0)
		return (NULL);
	fmted_str = gen_formatted_asterisk_rule(str_list_pop(splited_path, 0));
	joined_path = ft_strjoin(root, fmted_str);
	current_files = get_dir_list(joined_path);
	debug_dprintf(STDERR_FILENO, "fmted_rule %s\n", fmted_str);
	filtered = get_all_file_and_path(&current_files, fmted_str);
	str_list_print(filtered);
	free(fmted_str);
	// リストの要素が無いなら返る
	// ディレクトリであり、
	return (rlist);
}
