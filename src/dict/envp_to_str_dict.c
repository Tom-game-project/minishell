#include "dict.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/// keyを取得する関数を作る
static char *get_key_from_envp_ptr(char *str)
{
	unsigned int l;
	char *str_tmp;

	l = 0;
	str_tmp = str;
	while (*str != '=')
	{
		if (*str == '\0')
			return (NULL);
		l++;
		str++;
	}
	return (ft_substr(str_tmp, 0, l));
}

/// valueを取得する関数を作る
static char *get_value_from_envp_ptr(char *str)
{
	unsigned int s;
	char *str_tmp;

	s = 0;
	str_tmp = str;
	while (*str != '=')
	{
		if (*str == '\0')
			return (NULL);
		s++;
		str++;
	}
	return (ft_substr(str_tmp, s + 1, ft_strlen(str_tmp) - s - 1));
}


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
