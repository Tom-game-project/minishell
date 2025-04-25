/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:19:23 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:19:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void free_token_list(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
}

t_void_list	*heredoc_expand_string2list(char *str, t_str_dict *env_dicts)
{
	t_char_list	*path_group;
	t_char_list	*str_group;
	t_void_list	*rlist;

	str_group = NULL;
	path_group = NULL;
	rlist = NULL;
	while (*str != '\0')
	{
		anchor_heredoc_proc(\
			*str, \
			&(t_list_args){\
				&rlist, \
				&path_group, \
				&str_group}, \
			env_dicts);
		str++;
	}
	push_expand_env(&(t_list_args){
		&rlist, &path_group, &str_group}, env_dicts);
	push_str_group2(&(t_list_args){
		&rlist, &path_group, &str_group}, e_word);
	return (rlist);
}

char	*heredoc_expand_string(char *str, t_str_dict *env_dicts)
{
	t_str_list	*lst;
	char		*rstr;

	lst = heredoc_expand_string2list(str, env_dicts);
	rstr = token_list_join(lst);
	void_list_clear(&lst, free_token_list);
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
