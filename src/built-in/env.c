#include "libft.h"
#include "dict.h"

#include <unistd.h>
#include <stdlib.h>

/// env with no options or arguments
///
/// envに渡されたオプション、引数については、すべて無視する
///
/// minishellにおけるenvコマンドは、プロセスが保持する環境変数を返す
int built_in_env(t_str_dict *envp_dict)
{
    int exit_status;
    char **envp;
    int i;

    exit_status = 0;
    envp = str_dict_to_envp(envp_dict);
    i = 0;
    while (envp[i] != NULL)
    {
	    ft_putstr_fd(envp[i], STDOUT_FILENO);
	    ft_putstr_fd("\n", STDOUT_FILENO);
	    i += 1;
    }
    i = 0;
    while (envp[i] != NULL)
    {
	    free(envp[i]);
	    i += 1;
    }
    free(envp);
    return (exit_status);
}

