#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "list.h"
 //#include "test_tools.h"
#include "path.h"
#include "libft.h"
#include "test_tools.h"

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


/// "a*b*c" === "aacgggfafdbddddc" -> true
///              a---------b----c
/// "*.c" === "hello.c" -> true
///            -----.c
bool is_same_string(char *str, char *rule_str)
{
	if (rule_str[0] == '\0')
		return (str[0] == '\0');
	else if (str[0] == '\0')
		return (rule_str[0] == '*' && rule_str[1] == '\0');
	else if (rule_str[0] == '*')
	{
		if (rule_str[1] == str[0])
			rule_str++;
		else
			str++;
		return (is_same_string(str, rule_str));
	}
	else if (rule_str[0] == str[0])
	{
		rule_str++;
		str++;
		return (is_same_string(str, rule_str));
	}
	return (false);
}

bool is_same_string_wrap(t_anytype a, t_anytype b)
{
	return (is_same_string(a.str, b.str));
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

	rlist = NULL;
	if (str_list_len(*splited_path) == 0)
		return (NULL);
	fmted_str = gen_formatted_asterisk_rule(str_list_pop(splited_path, 0));
	current_files = get_dir_list(root);
	debug_dprintf(STDERR_FILENO, "fmted_rule %s\n", fmted_str);
	filtered = get_all_file_and_path(&current_files, fmted_str);
	str_list_print(filtered);
	free(fmted_str);
	// リストの要素が無いなら返る
	// ディレクトリであり、
	return (rlist);
}
