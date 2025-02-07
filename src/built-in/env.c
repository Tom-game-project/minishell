#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/// env with no options or arguments
///
/// envに渡されたオプション、引数については、すべて無視する
///
/// minishellにおけるenvコマンドは、プロセスが保持する環境変数を返す
int built_in_env(char *envp[])
{
    int exit_status;

    exit_status = 0;
    while (*envp != NULL)
    {
	    write (STDOUT_FILENO, *envp, ft_strlen(*envp));
	    write (STDOUT_FILENO, &"\n", 1);
	    envp++;
    }
    return (exit_status);
}

