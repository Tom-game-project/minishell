/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:21 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/02 18:56:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "list.h"
# include <stdbool.h>

bool	comb2_any(\
	t_char_list *lst, \
	t_str_list *rule_lst, \
	bool (*f)(t_char_list *str_lst, t_str_list *rule_list));

//bool is_same_string(t_char_list *target, t_str_list *rule_lst);

#endif
