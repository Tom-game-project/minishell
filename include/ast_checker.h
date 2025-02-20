/// # ast_checker.h
/// astが実行可能かを検査する
///
/// ここでのエラーは
/// syntax error として出力される
///
#ifndef AST_CHECKER_H
#define AST_CHECKER_H

#include "parser.h"

typedef enum e_syntax_result t_syntax_result;

enum e_syntax_result
{
	e_syntax_ok,
	e_ctl_near_unexpected_token_and,
	e_ctl_near_unexpected_token_or,
	e_rdt_near_unexpected_token_pipe,
	e_rdt_near_unexpected_token_rdt_in,
	e_rdt_near_unexpected_token_rdt_out,
	e_rdt_near_unexpected_token_heardoc_in,
	e_rdt_near_unexpected_token_heardoc_out,
	e_ctl_no_element_left_and_right,
	e_ctl_no_element_left_and_left,
	e_rdt_no_element_left_and_right,
	e_rdt_no_element_left_and_left,
};

t_syntax_result	check_ctl_adjacent(t_ast *ast);
t_syntax_result	check_rdt_adjacent(t_ast *ast);

#endif
