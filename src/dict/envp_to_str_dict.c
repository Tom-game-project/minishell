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
int envp_to_str_dict(t_str_dict **node, char *envp[])
{
	while (*envp != NULL)
	{
		str_dict_add(
			node,
			get_key_from_envp_ptr(*envp),
			get_value_from_envp_ptr(*envp),
			free
		);
		envp++;
	}
	return (0);
}
