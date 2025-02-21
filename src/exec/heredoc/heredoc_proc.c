#include "parser.h"

/// まず最初にheredocの入力だけを処理する,
///
/// heredoc内では部分的な環境変数展開が行われているようだ。
///
/// 再帰の構造と同じように処理する
int heredoc_proc(t_ast *ast)
{
	if (ast->ope != e_ope_heredoc_i)
	{
	}
	else
	{
	}
	return (0);
}


/// heredoc_fd_list内にfdを詰め込む
/// ヒアドキュメント
int heredoc_setup()
{
	return 0;
}
