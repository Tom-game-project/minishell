#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

/// この関数にstruct stat path_statを渡すと
/// シンボリックリンクだった場合なども考慮して設定される
int
set_stat(struct stat *path_stat, char *path)
{
	if (lstat(path, path_stat) != 0) 
	{
		perror("lstat");
		return (-1);
	}
	if (S_ISLNK(path_stat->st_mode))
	{
		if (stat(path, path_stat) != 0)
		{
			perror("stat");
			return (-1);
		}
	}
	return (0);
}

