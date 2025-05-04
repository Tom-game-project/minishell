/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_to_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:08:50 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:55:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// size_t str_dict_key_value_len(t_str_dict *node)
//{
//	size_t rlen;
//
//	rlen = 0;
//	rlen += ft_strlen(node->key);
//	rlen += 1; // "="
//	rlen = ft_strlen(node->value);
//	rlen += 1; // "\n"
//	return (rlen);
//}
//
// char *str_dict_node_to_str(t_str_dict *node)
//{
//	char *str;
//	char *str_tmp;
//	char *p;
//
//	str = (char *) malloc(sizeof(char) * (str_dict_key_value_len(node) + 1));
//	str_tmp = str;
//	p = node->key;
//	while (*p != '\0')
//		*str++ = *p++;
//	*str++ = '=';
//	p = node->value;
//	while (*p != '\0')
//		*str++ = *p++;
//	*str = '\0';
//	return (str_tmp);
//}

char	*str_dict_node_to_str(t_str_dict *node)
{
	char	*str;
	char	*str2;

	str = ft_strjoin(node->key, "=");
	str2 = ft_strjoin(str, node->value);
	free(str);
	return (str2);
}

///
/// ```
/// dict[
///     t_str_dict,
///     t_str_dict,
///     t_str_dict,
///     t_str_dict
///     ...
/// ]
/// ```
/// ->
/// ```
/// ft_strlen(char *:
///     key=value
///     key=value
///     key=value
///     key=value
/// ...
/// )
/// ```
///
// int str_dict_key_value_env_len(t_str_dict *node)
//{
//	int rlen;
//
//	rlen = 0;
//	while (node != NULL)
//	{
//		rlen += str_dict_key_value_len(node);
//		node = node->next;
//	}
//	return (rlen);
//}

// char *str_dict_to_env(t_str_dict *node)
//{
//	char *str;
//	char *str_tmp;
//
//	str = (char *) malloc(sizeof(char) * (str_dict_key_value_env_len(node)
//				+ 1));
//		;
//	str_tmp = str;
//	while ()
//	{
//	}
//	return ();
//}

///
/// ```
/// dict[
///     t_str_dict,
///     t_str_dict,
///     t_str_dict,
///     t_str_dict
///     ...
/// ]
/// ```
/// ->
/// ```
/// char **
/// [
///     "key=value", // char *
///     "key=value",
///     "key=value",
///     "key=value",
///      NULL
/// ]
/// ...
/// )
/// ```
char	**str_dict_to_envp(t_str_dict *node)
{
	char	**rarr;
	char	**rarr_tmp;

	rarr = (char **)malloc(sizeof(char *) * (str_dict_len(node) + 1));
	rarr_tmp = rarr;
	while (node != NULL)
	{
		*rarr = str_dict_node_to_str(node);
		node = node->next;
		rarr++;
	}
	*rarr = NULL;
	return (rarr_tmp);
}
