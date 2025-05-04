/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:39:16 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/04 15:39:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
#define PRIVATE_H

#include "list.h"
#include "dict.h"

t_str_list	*char_list2str_list(t_char_list **lst, t_str_dict *env_dict);
#endif
