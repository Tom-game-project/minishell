/// # expand_string.c
///
/// 環境変数の展開をする
///
#include "dict.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

t_str_list *expand_string2list(char *str, t_str_dict *env_dicts)
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

/// 環境変数展開済みの文字列が返却される
char *expand_string(char *str, t_str_dict *env_dicts)
{
	t_str_list *lst;
	char *rstr;

	lst = expand_string2list(str, env_dicts);
	rstr = str_list_join(lst, "");
	str_list_clear(&lst, free);
	return (rstr);
}

t_str_list *heredoc_expand_string2list(char *str, t_str_dict *env_dicts)
{
	t_char_list *path_group;
	t_char_list *str_group;
	t_str_list *rlist;

	str_group = NULL;
	path_group = NULL;
	rlist = NULL;
	while (*str != '\0')
	{
		anchor_heredoc_proc(
			*str, 
			&(t_list_args){
				&rlist,
			       	&path_group,
			       	&str_group}, 
			env_dicts
		);
		str++;
	}
	push_expand_env(&(t_list_args){
		&rlist, &path_group, &str_group}, env_dicts);
	push_str_group(&(t_list_args){
		&rlist, &path_group, &str_group});
	return (rlist);
}

char *heredoc_expand_string(char *str, t_str_dict *env_dicts)
{
	t_str_list *lst;
	char *rstr;

	lst = heredoc_expand_string2list(str, env_dicts);
	rstr = str_list_join(lst, "");
	str_list_clear(&lst, free);
	return (rstr);
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


/// minishellでは、$?を、環境変数として扱う
/// env内に入る

/// ```bash
/// $()"$()"'$()'
/// \---\----\----> 1. 展開される
///      \ ---\---> 2. 展開される
///            \--> 3. 展開されない
///
/// ```
/// 外、シングル、を解釈しつつスキップ、外側、またはdq内であれば$()展開
///
