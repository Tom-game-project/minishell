/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:07:35 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 19:09:06 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H

# define PRIVATE_H
# include "dict.h"
# include "list.h"
# include <stdbool.h>

///
///

typedef enum e_anchor		t_anchor;
enum						e_anchor
{
	e_anchor_out,
	e_anchor_dq,
	e_anchor_q,
};

typedef struct s_list_args	t_list_args;
struct						s_list_args
{
	t_void_list				**rlist;
	t_char_list				**path_group;
	t_char_list				**str_group;
};

// bool is_valid_env_char(char c);

int							push_str_group(t_list_args *group_args);

int							push_str_group2(t_list_args *group_args,
								t_expand_token_type token_type);

int							push_expand_env(t_list_args *group_args,
								t_str_dict *dict);

t_anchor					anchor_out_proc(char c, t_list_args *group_args,
								t_str_dict *env_dicts);

t_anchor					anchor_q_proc(char c, t_list_args *group_args);

t_anchor					anchor_dq_proc(char c, t_list_args *group_args,
								t_str_dict *env_dicts);

t_anchor					dollar_proc(char c, t_list_args *group_args,
								t_str_dict *env_dicts);

t_anchor					question_proc(char c, t_list_args *group_args,
								t_str_dict *env_dicts);

t_anchor					anchor_heredoc_proc(char c, t_list_args *group_args,
								t_str_dict *env_dicts);

t_anytype					alloc_ex_token(t_expand_token_type token_type,
								char *str);
#endif
