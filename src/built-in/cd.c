#include "list.h"
#include <unistd.h>
#include <stdio.h>


/// カレントディレクトリを変更する関数
/// ```bash
/// cd 
/// ```
/// ## case
/// - pathが存在しない
/// - pathがファイル
/// - return exit_status
int built_in_cd(t_str_list *args)
{
    char *path;

    if (str_list_len(args) < 2)
	    return (1);
    path = str_list_get_elem(args, 1);
    if (chdir(path) == -1)
    {
	    perror("minishell");
    }
    return (0);
}
