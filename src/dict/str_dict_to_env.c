/// 環境変数のフォーマットにする

#include "dict.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>


/// 渡された t_str_dictのnodeを
/// "key=value\n"で表現したときの文字列の長さをかえす
//size_t str_dict_key_value_len(t_str_dict *node)
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
///// 渡された t_str_dictのnodeを
///// "key=value"で表現した文字列にして返す
//char *str_dict_node_to_str(t_str_dict *node)
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

char *str_dict_node_to_str(t_str_dict *node)
{
	char *str;
	char *str2;

	str = ft_strjoin(node->key, "=");
	str2 = ft_strjoin(str, node->value);
	free(str);
	return (str2);
}

/// 改行区切りで`key=value`形式のデータを格納した際の長さを返す
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
//int str_dict_key_value_env_len(t_str_dict *node)
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

/// 渡されたt_str_dictをstring(char *)にする。
//char *str_dict_to_env(t_str_dict *node)
//{
//	char *str;
//	char *str_tmp;
//
//	str = (char *) malloc(sizeof(char) * (str_dict_key_value_env_len(node) + 1));
//		;
//	str_tmp = str;
//	while ()
//	{
//	}
//	return ();
//}
// <<< 使うかわからない微妙なラインなのでコメントアウト中

/// 渡されたt_str_dictを文字列配列(char **)にする。
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
char **str_dict_to_envp(t_str_dict *node)
{
	char **rarr;
	char **rarr_tmp;

	rarr = (char **)malloc(sizeof(char *) * (str_dict_len(node) + 1));
	rarr_tmp = rarr;
	while (node != NULL)
	{
		*rarr = str_dict_node_to_str(node); // TODO
		node = node->next;
		rarr++;
	}
	*rarr = NULL;
	return (rarr_tmp);
}

