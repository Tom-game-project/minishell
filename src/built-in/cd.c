#include <linux/limits.h>
#include "dict.h"
#include "list.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include "strtools.h"
#include "test_tools.h"

#define OLDPWD "OLDPWD"


/// カレントディレクトリを取得する関数
static
char *get_cd()
{
	char buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) == NULL)
	{
		perror("minishell");
		return (NULL);
	}
	return (ft_strdup(buf));
}

/// カレントディレクトリを変更する関数
/// ```bash
/// cd 
/// ```
/// ## case
/// - pathが存在しない
/// - pathがファイル
/// - return exit_status
///
/// `-` が来た際には環境変数のOLDPWDを参照する
/// これは、ユーザーが意図的に設定することが可能だがそれは問題ない
int built_in_cd(t_str_list *args, t_str_dict **envp_list)
{
    char *path;
    char *key_str;
    t_str_dict *d;

    if (str_list_len(args) < 2)
	    return (1);
    path = str_list_get_elem(args, 1);
    if (ft_streq(path, "-"))
    {
	    d = get_str_dict_by_key(*envp_list, OLDPWD);
	    if (d == NULL)
	    {
		    ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
		    return (1);
	    }
	    path = ft_strdup(d->value);
    }
    else
	    path = ft_strdup(path);
    // 移動する前にOLDPWDを更新する
    key_str = ft_strdup(OLDPWD);
    if (str_dict_add(envp_list, key_str, get_cd(), free) == 0)
	    free(key_str);
    debug_dprintf(STDERR_FILENO, "cd \"%s\"\n", path);
    if (chdir(path) == -1)
	    perror("minishell");
    free(path);
    return (0);
}

