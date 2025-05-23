/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tom_asterisk.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:44:39 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:45:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOM_ASTERISK_H
# define TOM_ASTERISK_H

# include "list.h"

// for test

t_str_list	*split_path_by_slash(char *path);
t_void_list	*split_token_list_by_slash(t_void_list *lst);

int			clear_split_token_list(t_void_list **token_list);

bool		is_same_string(t_char_list *target, t_void_list *rule_lst);

// t_str_list *filter_paths_by_rule(t_str_list **node, char *rule_str);

t_str_list	*filter_paths_by_rule_wrap(t_str_list **curr_lst,
				t_void_list *rule_list);

// char *gen_formatted_asterisk_rule(char *raw_rule);

t_str_list	*dir_walker(t_str_list **path, t_str_list *splited_path);

t_str_list	*rule_to_lst(char *rule_str);

bool		comb2_any(t_char_list *lst, t_str_list *rule_lst,
				bool (*f)(t_char_list *str_lst, t_str_list *rule_list));
#endif
