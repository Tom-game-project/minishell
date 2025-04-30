#include "path.h"
#include <stdbool.h>
#include <sys/stat.h>

// 渡されたpathがディレクトリのときにtrueを返す関数
bool is_dir(char *path)
{
	struct stat path_stat;

	set_stat(&path_stat, path);
	return (S_ISDIR(path_stat.st_mode));
}

