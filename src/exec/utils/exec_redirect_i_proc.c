#include "dict.h"
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
///
///
int exec_redirect_i_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd)
{
	if (input_fd != STDIN_FILENO)
		close(input_fd); // 
	// ファイルの指定がある場合はここで開く
	input_fd = open();
	return (0);
}
