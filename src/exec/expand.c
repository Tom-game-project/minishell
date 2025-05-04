/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:38:36 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/01 19:38:59 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "exec.h"
#include "list.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_vec_vec_str(t_anytype elem)
{
	(void)elem;
}

/// 未展開の引数リストを受け取って、展開済みの新しい引数を返却する
t_str_list	*expand_env_vars(t_str_list *args, t_str_dict *env)
{
	t_void_list	*vec_vec_str;
	t_str_list	*rlist;
	t_anytype	elem;

	vec_vec_str = NULL;
	while (args != NULL)
	{
		elem.list = expand_env_var(args->ptr.str, env);
		void_list_push(&vec_vec_str, elem);
		args = args->next;
	}
	rlist = list_list_all_concat(vec_vec_str);
	void_list_clear(&vec_vec_str, free_vec_vec_str);
	return (rlist);
}
