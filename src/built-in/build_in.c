/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:21:09 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:21:18 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "strtools.h"

/// 与えられたコマンドがbuilt in関数であるかどうかを判別して、
/// built_inごとに指定された列挙型を返却する
t_built_in	get_built_in_enum(char *cmd)
{
	if (ft_streq(cmd, "pwd"))
		return (e_built_in_pwd);
	else if (ft_streq(cmd, "cd"))
		return (e_built_in_cd);
	else if (ft_streq(cmd, "export"))
		return (e_built_in_export);
	else if (ft_streq(cmd, "unset"))
		return (e_built_in_unset);
	else if (ft_streq(cmd, "env"))
		return (e_built_in_env);
	else if (ft_streq(cmd, "exit"))
		return (e_built_in_exit);
	else if (ft_streq(cmd, "echo"))
		return (e_built_in_echo);
	else
		return (e_not_built_in);
}
