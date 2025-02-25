#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/// コマンドとパスをくっつけて、フルパスを作る
static char *join_path_and_free_func(char *a, char *b)
{
	char *rstr;
	char *tmp;

	tmp = ft_strjoin(a, "/");
	free(a);
	rstr = ft_strjoin(tmp, b);
	free(tmp);
	return (rstr);
}

/// 実行可能かどうかを判定する
static bool check_exist_cmd(char *str)
{
	return (access(str, F_OK) == 0);
}

/// 環境変数に基づいて、実行可能なフルパスを渡す
/// 
/// 子プロセスで、最後に使うため
/// 確保をするが、解放はしなくて良い
/// コマンド(実行しようと思っているコマンド)
/// `char *cmd`
/// 環境変数(コロン区切りのパスを格納したデータ)
/// `char *env_path`
char *get_full_path(char *cmd, char *env_path)
{
	t_str_list *env_l;
	char *rstr;

	if (check_exist_cmd(cmd))
		return (ft_strdup(cmd));
	if (env_path == NULL)
		return (NULL);
	env_l = NULL;
	env_l = str_list_split(env_path, ':'); // コロン区切りの形式を、リストに変換する
	str_list_map_arg1(&env_l, join_path_and_free_func, cmd); // ここで、考えられるフルパスをすべて列挙する
	rstr = str_list_search(env_l, check_exist_cmd);// 上げたフルパスの中で実行可能の判定が出るものを探す
	if (rstr == NULL)
	{
		str_list_clear(&env_l, free); // 使い終わったリストの解放
		return (NULL);
	}
	else
	{
		rstr = ft_strdup(rstr);
		str_list_clear(&env_l, free); // 使い終わったリストの解放
	}
	return (rstr);
}

