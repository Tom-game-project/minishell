#include <unistd.h>
#include <stdio.h>


/// カレントディレクトリを変更する関数
/// return exit_status
/// ```
/// ```
int built_in_cd(char *path)
{
    int exit_status;

    exit_status = 0;
    if (chdir(path) == -1)
    {
	    perror("minishell");
	    exit_status = 1;
    }
    return (exit_status);
}
