/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:11:11 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:12:11 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "parser.h"
# include <stdbool.h>

t_ast		*init_ast(void);

t_operator	str2ope(char *str);

bool		startswith_open_paren(char *str);

bool		is_rdt_string(char *str);

bool		is_ope_string(char *str);

int			remove_ifs(t_str_list **lst);

bool		tom_syntax_checker(char *input);

bool is_ifs(char c);

bool is_ope_char(char c);

#endif
