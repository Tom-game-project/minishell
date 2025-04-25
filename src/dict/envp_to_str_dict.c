/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_str_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:28:21 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:28:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "envtools.h"
#include <stdlib.h>
#include <stdio.h>

/// envpをstr_dictに変換する関数
/// 第一引数に渡されたディクショナリに、解釈されたenvpが渡される
///
/// 何らかの理由で格納に失敗した場合は理由は1を返却する
///
/// # TODO
/// 返り値は列挙型に変更される可能性がある
///
int	envp_to_str_dict(t_str_dict **node, char *envp[])
{
	char *str;

	while (*envp != NULL)
	{
		str = get_key_from_envp_ptr(*envp);
		if (
			str_dict_add(
			node,
			str,
			get_value_from_envp_ptr(*envp),
			free) == 0)
			free(str);
		envp++;
	}
	return (0);
}
