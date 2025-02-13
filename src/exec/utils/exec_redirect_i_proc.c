#include "dict.h"
#include "parser.h"
#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>



/// ファイルをつないで、書き込み側のパイプにつなげる
int exec_redirect_i_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd)
{
	// TODO
	return (0);
}
