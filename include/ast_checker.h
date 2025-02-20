/// # ast_checker.h
/// astが実行可能かを検査する
///
/// ここでのエラーは
/// syntax error として出力される
///
#ifndef AST_CHECKER_H
#define AST_CHECKER_H

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
};

#endif
