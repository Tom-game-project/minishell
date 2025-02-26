/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:49:29 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:50:01 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOID_LIST_H
# define VOID_LIST_H

# include <stdbool.h>

typedef void	*(*t_v2vfunc)(void *);

typedef void	*(*t_vv2vfunc)(void *, void *);

typedef bool	(*t_v2bfunc)(void *);

typedef bool	(*t_vv2bfunc)(void *, void *);

#endif
