#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "list.h"
#include "path.h"
#include "libft.h"
#include "test_tools.h"
#include "exec.h"
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

static char *
remove_slash(char *str)
{
	if (endwith_srash(str))
		return (ft_substr(str, 0, ft_strlen(str) - 1));
	else
		return (ft_strdup(str));
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
		rstr = ft_substr(raw_rule, 0, len - 1);
	else
		rstr = ft_strdup(raw_rule);
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

static bool func_wrap(t_anytype a, t_anytype b) 
{
	t_char_list *c_lst;
	t_str_list *rule_lst;
	bool r;

	c_lst = NULL;
	char_list_push_str(&c_lst, a.str);
	rule_lst = rule_to_lst(b.str);
	r = is_same_string(c_lst, rule_lst);
	char_list_clear(&c_lst);
	str_list_clear(&rule_lst, free);
	return (r);
}

t_str_list *
get_all_file_and_path(t_str_list **node, char *rule_str)
{
	t_anytype rule_str_anytype;

	rule_str_anytype.str = rule_str;
	return (void_list_filter2(
		node,
	       	func_wrap,
	       	rule_str_anytype
	));
}

t_str_list *
get_all_path(t_str_list **path, t_str_list *splited_path)
{
	t_char_list *rlist;
	t_str_list *curr_lst;

	rlist = NULL;
	if (str_list_len(splited_path) == 0)
		return (NULL);
	if (str_list_len(*path) == 0)
	{
		if (ft_streq(splited_path->ptr.str, ".."))
		{
			curr_lst = get_dir_list("..");
			splited_path = splited_path->next;
		}
		else if (ft_streq(splited_path->ptr.str, "/"))
		{
			curr_lst = get_dir_list("/");
			str_list_push(path, ft_strdup("/"));
			splited_path = splited_path->next;
		}
		else if (ft_streq(splited_path->ptr.str, "."))
		{
			curr_lst = get_dir_list(".");
			splited_path = splited_path->next;
		}
		else
			curr_lst = get_dir_list(".");
	}
	else
	{
		char *str;

		str = str_list_join(*path, "");
		curr_lst = get_dir_list(str);
		free(str);
	}

	t_str_list *filtered;
	char *slash_removed_str;

	slash_removed_str = remove_slash(splited_path->ptr.str);
	filtered = get_all_file_and_path(&curr_lst, slash_removed_str);
	free(slash_removed_str);
	str_list_clear(&curr_lst, free);
	if (str_list_len(splited_path) == 1) 
	{
		t_str_list *filtered_ptr;
		char *parent_path;

		filtered_ptr = filtered;
		parent_path = str_list_join(*path, "");
		while (filtered_ptr != NULL)
		{
			str_list_push(
				&rlist,
				ft_strjoin(
					parent_path,
					filtered_ptr->ptr.str));
			filtered_ptr = filtered_ptr->next;
		}
		free(parent_path);
		str_list_clear(&filtered, free);
		return (rlist);
	}else
	{
		t_str_list *filtered_ptr;
		t_str_list *path_ptr;

		filtered_ptr = filtered;
		path_ptr = *path;
		while (str_list_len(filtered_ptr) != 0)
		{
			t_str_list *filtered_head;
			t_str_list *path_tmp;

			filtered_head = str_list_cut(&filtered_ptr, 0);
			str_list_concat(&path_ptr, filtered_head);
			str_list_push(&path_ptr, ft_strdup("/"));
			str_list_concat(&rlist, get_all_path(&path_ptr, splited_path->next));
			path_tmp = str_list_cut(&path_ptr, str_list_len(path_ptr) - 1 - 2);
			str_list_clear(&path_ptr, free);
			path_ptr = path_tmp;
		}
		return (rlist);
	}
}
