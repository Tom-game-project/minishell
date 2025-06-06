/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tom_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:52:31 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:52:32 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "private.h"
#include "tom_parser.h"
//#include "test_tools.h"
#include <stdbool.h>
#include <unistd.h>

///
/// bool
static bool	cur_out_of_quotation(t_cur_anchor *s)
{
	if (s->c == '\'')
		*s->anchor = e_in_q;
	else if (s->c == '"')
		*s->anchor = e_in_dq;
	else if (s->c == '(')
		*s->depth += 1;
	else if (s->c == ')')
	{
		*s->depth -= 1;
		if (*s->depth == 0)
		{
			*s->cut_list = char_list_cut(s->clst, s->idx);
			return (true);
		}
	}
	else if (*s->depth == 0 && (is_ifs(s->c) || is_ope_char(s->c)))
	{
		*s->cut_list = char_list_cut(s->clst, s->idx - (s->idx != 0));
		return (true);
	}
	return (false);
}

static bool	cur_loop(t_cur_anchor *s)
{
	if (*s->anchor == e_outof_q)
	{
		if (cur_out_of_quotation(s))
			return (true);
	}
	else if ((*s->anchor == e_in_dq && s->c == '"') || (*s->anchor == e_in_q
			&& s->c == '\''))
	{
		*s->anchor = e_outof_q;
		if (*s->depth == 0)
		{
			*s->cut_list = char_list_cut(s->clst, s->idx);
			return (true);
		}
	}
	return (false);
}

static bool	char_iter(t_char_list **clst, int idx, char *c)
{
	*c = char_list_get_elem(*clst, idx);
	return (*c != '\0');
}

/// ```bash
/// ls -la &&(cat ) | "hello world"
/// ```
/// -ls -la &&(cat ) | "hello world">
/// ```
/// 'ls' '-la' '&&' '(cat )' '|' '"hello world"'
/// ```
///
/// ```
/// `<`, `>`, `|`, `||`, `&&`, `<<`, `>>`
/// ```
static t_char_list	*pre_lexer(t_char_list **clst)
{
	t_anchor	p;
	int			depth;
	int			idx;
	t_char_list	*cut_list;
	char		c;

	depth = 0;
	idx = 0;
	p = e_outof_q;
	cut_list = NULL;
	while (char_iter(clst, idx, &c))
	{
		if (cur_loop(&(t_cur_anchor){c, &p, &depth, idx, clst, &cut_list}))
			return (cut_list);
		idx += 1;
	}
	return (char_list_cut(clst, idx));
}

t_str_list	*lexer(char *str)
{
	t_char_list	*lst;
	char		*s;
	t_char_list	*head;
	t_str_list	*lexed;

	lst = NULL;
	char_list_push_str(&lst, str);
	lexed = NULL;
	while (1)
	{
		head = pre_lexer(&lst);
		if (head == NULL)
			break ;
		s = char_list_to_str(head);
		char_list_clear(&head);
		str_list_push(&lexed, s);
	}
	ope_collector(&lexed);
	return (lexed);
}
