#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// ファイルをつないで、書き込み側のパイプにつなげる
///
/// 右astを優先して処理していく,
///
/// 仕様の決定が曖昧なところはあるが、、
///
/// ```bash
/// cat < infile < infile2 -e
/// ```
///
int exec_redirect_i_proc(t_ast *ast, t_str_dict *envp_dict, int *input_fd)
{
	char *str;
	(void) envp_dict; // TODO: あとで展開に使う

	if (input_fd != STDIN_FILENO)
		close(*input_fd); // 
	// ファイルの指定がある場合はここで開く
	str = str_list_get_elem(ast->arg, 0);
	if (str == NULL) // NULL
	{
		//TODO:もし見つからなければ
	}
	*input_fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*input_fd == -1)
	{
		// file open error
		return (1);
	}
	return (0);
}
