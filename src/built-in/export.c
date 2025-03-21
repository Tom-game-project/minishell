/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:26:08 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:07:52 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "list.h"
#include "libft.h"
#include "envtools.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>

/// exportは子プロセスを読んでいるようにみえて、親で実行する
///
/// 保持しているenvpのディクショナリ構造を、リスト構造に直してもう一度envpに渡す
///
///
/// 与えられた引数で、exportを試みられたものの環境変数をすべて設定する
///
/// ```bash
/// ❱ export hello=hello
/// ❱ export hello
/// ❱ echo $hello
/// hello
/// ```
///
///
/// ```bash
/// export hello=hello world=world
/// ```
///
/// 環境変数に使えない文字が入る場合は
/// 以下のようなエラーが出力される
/// exit status は1を返却する
/// ```
/// ❱ export =hello
/// bash: export: `=hello': not a valid identifier
/// ```

static
int	set_envp(
	t_str_dict **envp_dict,
	char *key,
	char *value
)
{
	if (ft_strlen(key) == 0)
	{
		return (1);
	}
	if (is_valid_identifier(key))
	{
		debug_dprintf(\
			STDERR_FILENO, "new env added key: \"%s\", value: \"%s\"\n", key, value);
		if (value == NULL)
			return (0);
		str_dict_add(envp_dict, key, value, free);
		return (0);
	}
	else
	{
		return (1);
	}
}

int	built_in_export(
	t_str_list *args,
	t_str_dict **envp_dict
)
{
	char	*line;

	(void) envp_dict;
	args = args->next;
	while (args != NULL)
	{
		line = args->ptr.str;
		set_envp(
			envp_dict,
			get_key_from_envp_ptr(line),
			get_value_from_envp_ptr(line));
		args = args->next;
	}
	return (0);
}
