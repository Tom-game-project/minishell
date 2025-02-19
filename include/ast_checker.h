/// # ast_checker.h
/// astが実行可能かを検査する
///
/// ここでのエラーは
/// syntax error として出力される
///
#ifndef AST_CHECKER_H
#define AST_CHECKER_H

typedef enum e_syntax_result t_syntax_result;

/// エラー構造体
///
/// e_syntax_ok: 問題がない場合
enum e_syntax_result
{
	e_syntax_ok,
};


#endif
