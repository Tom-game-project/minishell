/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:11:11 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 21:41:18 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "parser.h"
# include <stdbool.h>

typedef enum e_anchor	t_anchor;
enum e_anchor
{
	e_in_q,
	e_in_dq,
	e_outof_q
};

typedef struct s_cur_anchor t_cur_anchor;
/// TODO: rename 必須
struct s_cur_anchor
{
	char c;
	t_anchor *anchor;
	int *depth;
	int idx;
	t_char_list **clst;
	t_char_list **cut_list; // NULLで渡す
};


t_ast		*init_ast(void);

t_operator	str2ope(char *str);

bool		startswith_open_paren(char *str);

bool	is_pipe_string(char *str);

bool		is_rdt_string(char *str);

bool		is_ope_string(char *str);

int			remove_ifs(t_str_list **lst);

bool		tom_syntax_checker(char *input);

bool		is_ifs(char c);

bool		is_ope_char(char c);

#endif
