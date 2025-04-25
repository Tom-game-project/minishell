/// # expand_string.c
///
/// 環境変数の展開をする
///
#include "dict.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "utils/private.h"

/// 文字列の展開
/// 
/// example
/// ```
/// "\"  $PATH  \"\"   hello  \""
/// return ("  $展開済みPATH     hello  ")
/// ```
///
/// example
/// ```
/// "\"Tom\"\"'\"\"s Home Party\""
/// return ("Tom's Home Party")
/// ```
///
/// example
/// ```
/// "$PATH"
/// return ("$展開済みPATH")
/// ```
/// return new_string
///
/// アスタリスクを特別に解釈する必要があるので、トークンリストを返す
t_void_list	*expand_string2list2(char *str, t_str_dict *env_dicts)
{
	t_anchor	anc;
	t_char_list	*path_group;
	t_char_list	*str_group;
	t_void_list	*rlist;

	anc = e_anchor_out;
	str_group = NULL;
	path_group = NULL;
	rlist = NULL;
	while (*str != '\0')
	{
		if (anc == e_anchor_out)
			anc = anchor_out_proc(*str, &(t_list_args){\
				&rlist, &path_group, &str_group}, env_dicts);
		else if (anc == e_anchor_q)
			anc = anchor_q_proc(*str, &(t_list_args){\
				&rlist, &path_group, &str_group});
		else if (anc == e_anchor_dq)
			anc = anchor_dq_proc(*str, &(t_list_args){\
				&rlist, &path_group, &str_group}, env_dicts);
		str++;
	}
	push_expand_env(&(t_list_args){
		&rlist, &path_group, &str_group}, env_dicts);
	push_str_group2(&(t_list_args){
		&rlist, &path_group, &str_group}, e_word);
	return (rlist);
}

