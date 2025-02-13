#include "dict.h"
#include "list.h"
#include "parser.h"
#include "path.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// 扱いやすい引数を渡すことで実行できるexecve
/// この関数では以下の処理を行う
/// - 環境変数の展開
/// - $()展開 (この関数が更に子プロセスを生じさせる可能性がある)
int execve_wrap(t_ast *ast, t_str_dict *envp_dict)
{
	char *fullpath;
	char *cmd;
	char **argv;
	char **envp;
	t_str_dict *env_path_node;

	cmd = str_list_get_elem(ast->arg, 0); // 0番目の要素を取り出す
	argv = str_list_to_array(ast->arg);
	env_path_node = get_str_dict_by_key(envp_dict, "PATH");
	if (env_path_node == NULL) // 環境変数に`PATH`が見つからない
	{
		// TODO
		// あとで実装する必要がある
		exit(1);
	}
	// PATH環境変数を解析して実行可能なフルパスを検索
	fullpath = get_full_path(cmd, env_path_node->value);
	// TODO: 実行すべきpathはこれだけではないはずなので、
	// get_full_pathはあとから更に機能追加が必要
	// TODO WARN
	// fullpathはNULLになって返る可能性がある
	envp = str_dict_to_envp(envp_dict); // 環境変数をexecveに渡せる形に固定する
	dprintf(STDERR_FILENO, "cmd %s running on pid(%d, -> ppid(%d))\n", fullpath, getpid(), getppid());
	execve(fullpath, argv, envp);
	return (1);// ここに到達した場合は不正
}

