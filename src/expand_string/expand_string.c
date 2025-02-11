/// # expand_string.c
///
/// 環境変数の展開をする
///
#include "dict.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils/expand_string.h"

/// 文字列の展開
/// 
/// example
/// ```
/// "\"  $PATH  \"\"   hello  \""
/// return ("  $展開済みPATH     hello  ")
/// ```
///
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
t_str_list *expand_string(char *str, t_str_dict *env_dicts)
{
	t_anchor anc;
	t_char_list *path_group;
	t_char_list *str_group;
	t_str_list *rlist;

	anc = e_anchor_out;
	str_group = NULL;
	path_group = NULL;
	rlist = NULL;
	while (*str != '\0')
	{
		//printf("[%c][%d]\n", *str, anc);
		//char_list_print(path_group);
		if (anc == e_anchor_out)
			anc = anchor_out_proc(*str, &(t_list_args){
				&rlist, &path_group, &str_group}, env_dicts);
		else if (anc == e_anchor_q)
			anc = anchor_q_proc(*str, &(t_list_args){
				&rlist, &path_group, &str_group});
		else if (anc == e_anchor_dq)
			anc = anchor_dq_proc(*str, &(t_list_args){
				&rlist, &path_group, &str_group}, env_dicts);
	       	// else is unreachable
		str++;
	}
	push_expand_env(&(t_list_args){
		&rlist, &path_group, &str_group}, env_dicts);
	push_str_group(&(t_list_args){
		&rlist, &path_group, &str_group});
	return (rlist);
}

/// 文字列の展開
/// 環境変数を展開する
/// example
/// ```
/// ["\"  $PATH  \"\"   hello  \"", "'$PATH'", NULL]
/// ["\"  $PATH  \"'   hello  '", "'$PATH'", NULL]
/// ```
///
/// "$ENV"   '$ENV'
/// 展開する  展開しない
/// return ["展開済みstring", "展開済みstring", ... , NULL]
//char **expand_args(char **cmd_args, t_str_dict *env_dicts)
//{
//	// get_str_dict_by_key();
//	return ();
//}
