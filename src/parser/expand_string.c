#include "dict.h"
#include "libft.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum e_anchor t_anchor;
enum e_anchor
{
	e_anchor_out,
	e_anchor_dq,
	e_anchor_q, 
};

/// 環境変数として使用可能な文字かどうかを判別する
/// 
/// a-zA-Z0-9
/// アンダースコア(_)
/// 
bool is_valid_env_char(char c)
{
	return (\
		('a' <= c && c <= 'z') || \
		('A' <= c && c <= 'Z') || \
		('0' <= c && c <= '9') || \
		('_' == c)
	);
}

/// プライベートな構造体
typedef struct s_list_args t_list_args;
struct s_list_args
{
	t_str_list **rlist;
	t_char_list **path_group;
	t_char_list **str_group;
};

/// path_groupを展開してrlistに追加する
static int push_expand_env(t_list_args *group_args, t_str_dict *dict)
{
	t_str_dict *r;

	if (!char_list_is_empty(*group_args->path_group)) // 空じゃないとき
	{
		char_list_pop(group_args->path_group, 0); // `$`を取り除く
		// printf("Key %s\n", char_list_to_str(*group_args->path_group));
		r = get_str_dict_by_key(dict, char_list_to_str(*group_args->path_group));
		if (r == NULL)
		{// printf("not found\n");
		}
		else
		{// printf("Value %s\n", r->value);
			str_list_push(group_args->rlist, ft_strdup(r->value));
		}
		char_list_clear(group_args->path_group);
	}
	return (0);
}

/// str_groupをrlistに追加する
static int push_str_group(t_list_args *group_args)
{
	if (!char_list_is_empty(*group_args->str_group))
	{
		str_list_push(group_args->rlist, char_list_to_str(*group_args->str_group));
		char_list_clear(group_args->str_group);
	}
	return (0);
}

/// クォーテーション外の処理
static t_anchor anchor_out_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	if (c == '\'') // quotation open
	{
		push_expand_env(group_args, env_dicts);
		push_str_group(group_args);
		return (e_anchor_q);
	}
	else if (c == '"')// double quotation open
	{
		push_expand_env(group_args, env_dicts);
		push_str_group(group_args);
		return (e_anchor_dq);
	}
	else if (c == '$')
	{
		push_str_group(group_args);
		char_list_push(group_args->path_group, c);
	}
	else
		if (!char_list_is_empty(*group_args->path_group))
			if (is_valid_env_char(c))
				char_list_push(group_args->path_group, c);
			else
			{
				push_expand_env(group_args, env_dicts);
				push_str_group(group_args);
				char_list_push(group_args->str_group, c);
			}
		else
			char_list_push(group_args->str_group, c);
	return (e_anchor_out);
}

/// シングルクォーテーション内の処理
static t_anchor anchor_q_proc(char c, t_list_args *group_args)
{
	if (c == '\'') // quotation close
	{
		push_str_group(group_args);
		return (e_anchor_out);
	}
	else
		char_list_push(group_args->str_group, c);
	// `"`を普通の文字と同じように解釈する
	return (e_anchor_q);
}

/// ダブルクォーテーション中の処理
static t_anchor anchor_dq_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	if (c == '"')// double quotation open
	{
		push_expand_env(group_args, env_dicts);
		push_str_group(group_args);
		return (e_anchor_out);
	}
	else if (c == '$')
	{
		push_str_group(group_args);
		char_list_push(group_args->path_group, c);
	}
	else
		if (!char_list_is_empty(*group_args->path_group))
			if (is_valid_env_char(c))
				char_list_push(group_args->path_group, c);
			else
			{
				push_expand_env(group_args, env_dicts);
				push_str_group(group_args);
				char_list_push(group_args->str_group, c);
			}
		else
			char_list_push(group_args->str_group, c);
	return (e_anchor_dq);
}

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
/// 環境変数に基づいて、execveに渡せる形に整形する
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
