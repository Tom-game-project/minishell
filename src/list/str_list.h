/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:51 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:42:44 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_LIST_H
# define STR_LIST_H

# include "list.h"

t_str_list	*str_list_get_back(t_str_list *node);

t_str_list	*str_list_get_ptr(t_str_list *head, int index);

int			str_list_len_sum(t_str_list *node);

#endif
