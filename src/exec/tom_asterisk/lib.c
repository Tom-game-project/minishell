#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "list.h"
#include "test_tools.h"

static bool is_slash(char *c)
{
	return (*c == '/');
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
	if (*rule_str == '\0')
		return (true);
	else if (*str == '\0')
		return (*rule_str == '*'); // ルールが残っているのにnull文字
	else if (*rule_str == '*')
	{
		if (rule_str[1] == str[0])
			rule_str++;
		else
			str++;
		return (is_same_string(str, rule_str));
	}
	else if (*rule_str == *str)
	{
		rule_str++;
		str++;
		return (is_same_string(str, rule_str));
	}
	else
		return false;
}
