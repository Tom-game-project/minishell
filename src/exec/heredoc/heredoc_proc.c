#include "parser.h"
#include "list.h"
#include "libft.h"
#include <stdlib.h>

#include "heredoc.h"

/// まず最初にheredocの入力だけを処理する,
///
/// heredoc内では部分的な環境変数展開が行われているようだ。
///
/// 再帰の構造と同じように処理する
int heredoc_proc(t_ast *ast, t_int_list **heredoc_fd_list)
{
	char *str;
	char *strl;
	int rw_fd[2];

	if (ast->ope == e_ope_heredoc_i)
	{
		str = str_list_get_elem(ast->arg, 0);
		strl = ft_strjoin(str, "\n"); // EOF
		if (create_shadow_file(rw_fd) == -1)
			return (1);
		read_heredocline(strl, rw_fd[1]);
		free(strl);
		close(rw_fd[1]);
		int_list_push(heredoc_fd_list, rw_fd[0]);
	}
	if (ast->left_ast != NULL)
		return (heredoc_proc(ast->left_ast, heredoc_fd_list));
	if (ast->right_ast != NULL)
		return (heredoc_proc(ast->right_ast, heredoc_fd_list));
	return (0);
}

