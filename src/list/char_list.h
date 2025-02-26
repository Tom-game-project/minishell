/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:20:10 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:20:28 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_LIST_H
# define CHAR_LIST_H

# include "list.h"

t_char_list	*char_list_get_ptr(t_char_list *head, int index);

//t_char_list *get_back(t_char_list *node);
t_char_list	*char_list_get_back(t_char_list *node);

#endif
