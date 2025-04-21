/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:38:27 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:40:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "list.h"
#include "libft.h"
#include "tom_parser.h"
#include "parser.h"
#include "private.h"

/// L ope R
static t_parse_result	parse_ope_string(\
	t_ast *orig, t_str_list *input, int index)
{
	t_str_list		*left_input;
	t_str_list		*right_input;
	t_parse_result	result;
	char			*ope_str;

	ope_str = str_list_pop(&input, index);
	left_input = str_list_cut(&input, index - 1);
	right_input = input;
	orig->ope = str2ope(ope_str);
	free(ope_str);
	if (str_list_len(left_input) != 0)
	{
		orig->left_ast = init_ast();
		result = tom_parser_lexed(&orig->left_ast, left_input);
		if (result != e_result_ok)
			return (result);
	}
	if (str_list_len(right_input) != 0)
	{
		orig->right_ast = init_ast();
		result = tom_parser_lexed(&orig->right_ast, right_input);
		if (result != e_result_ok)
			return (result);
	}
	return (e_result_ok);
}

/// L ope R
/// ope LR
static t_parse_result	parse_rdt_string(\
	t_ast *orig, t_str_list *input, int index)
{
	t_str_list		*left_input;
	t_str_list		*right_input;
	char			*ope_str;
	t_parse_result	result;

	ope_str = str_list_pop(&input, index);
	left_input = str_list_cut(&input, index - 1);
	right_input = input;
	remove_ifs(&right_input);
	orig->arg = str_list_cut(&right_input, 0);
	orig->right_ast = NULL;
	str_list_concat(&left_input, right_input);
	orig->ope = str2ope(ope_str);
	free(ope_str);
	if (str_list_len(left_input) != 0)
	{
		orig->left_ast = init_ast();
		result = tom_parser_lexed(&orig->left_ast, left_input);
		if (result != e_result_ok)
			return (result);
	}
	return (e_result_ok);
}

static t_parse_result	parse_paren_string(\
	t_ast *orig, t_str_list *input)
{
	char	*str;
	char	*cutstr;

	str = str_list_pop(&input, 0);
	cutstr = ft_substr(str, 1, ft_strlen(str) - 2);
	free(str);
	orig->ope = e_ope_paren;
	tom_parser(cutstr, &orig->left_ast);
	free(cutstr);
	return (e_result_ok);
}

/// 字句解析処理後のリストを引数に取る
t_parse_result	tom_parser_lexed(t_ast **ast, t_str_list *input)
{
	int		index;
	t_ast	*orig;

	orig = *ast;
	remove_ifs(&input);
	// パイプのときは、str_list_search_index関数を使う
	index = str_list_search_index(input, is_pipe_string);
	if (index != -1)
		return (parse_ope_string(orig, input, index));
	index = str_list_search_index_r(input, is_ope_string);
	if (index != -1)
		return (parse_ope_string(orig, input, index));
	index = str_list_search_index(input, is_rdt_string);
	if (index != -1)
		return (parse_rdt_string(orig, input, index));
	if (
		str_list_len(input) == 1 && \
		startswith_open_paren(str_list_get_elem(input, 0))
	)
		return (parse_paren_string(orig, input));
	split_by_ifs(&input, free);
	orig->arg = input;
	orig->ope = e_ope_none;
	return (e_result_ok);
}

/// 字句解析前のコマンドライン文字列を引数に取る
t_parse_result	tom_parser(char *input, t_ast **ast)
{
	t_str_list	*lexed;

	*ast = init_ast();
	if (!tom_syntax_checker(input))
		return (e_result_paren_not_closed_err);
	lexed = lexer(input);
	tom_parser_lexed(ast, lexed);
	return (e_result_ok);
}

