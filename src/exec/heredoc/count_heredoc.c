#include "parser.h"
#include <stdlib.h>

/// here docのインターフェイス
/// ユーザの入力を受け取る関数

/// astが含んでいるheredocの数をカウントする関数
int count_heredoc(t_ast *ast)
{
	int count;

	count = 0;
	if (ast == NULL)
		return (count);
	if (ast->ope == e_ope_heredoc_i)
		count += 1;
	count += count_heredoc(ast->left_ast);
	count += count_heredoc(ast->right_ast);
	return (count);
}

