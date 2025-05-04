/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:59:04 by kaara             #+#    #+#             */
/*   Updated: 2025/05/04 16:03:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_CHECKER_H
# define AST_CHECKER_H

# include "parser.h"

typedef enum e_syntax_result	t_syntax_result;
typedef t_syntax_result			(*t_check_func)(t_ast *);

enum e_syntax_result
{
	e_syntax_ok,
	e_no_input,
	e_syntax_near_unexpected_token_string,
	e_ctl_near_unexpected_token_and,
	e_ctl_near_unexpected_token_or,
	e_rdt_near_unexpected_token_pipe,
	e_rdt_near_unexpected_token_newline,
	e_rdt_near_unexpected_token_rdt_in,
	e_rdt_near_unexpected_token_rdt_out,
	e_rdt_near_unexpected_token_heardoc_in,
	e_rdt_near_unexpected_token_heardoc_out,
	e_rdt_near_unexpected_token_rdt,
	e_ctl_no_element_left_and_right,
	e_ctl_no_element_left_and_left,
	e_rdt_no_element_left_and_right,
	e_rdt_no_element_left_and_left,
};

bool			ast_checker_wrap2(t_ast **ast);

//ast_checker.c
t_syntax_result	ast_checker(t_ast	*ast);

//ast_checker_u.c
bool			is_enum_rdtope(t_operator ope);

//check_case
t_syntax_result	check_no_input(t_ast *ast);
t_syntax_result	check_ctl_no_element(t_ast *ast);
t_syntax_result	check_pipe_no_arg(t_ast *ast);
t_syntax_result	check_rdt_no_arg(t_ast *ast);
t_syntax_result	check_rdt_no_element(t_ast *ast);
t_syntax_result	check_element(t_ast *ast);
t_syntax_result	check_adjacent_strings(t_ast *ast);

//print
bool			print_checker_result(t_syntax_result result);

#endif
