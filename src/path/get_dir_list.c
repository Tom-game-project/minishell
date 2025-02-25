#include "list.h"
#include "libft.h"

#include <dirent.h>
#include <stdlib.h>

t_str_list *
get_dir_list(char *name)
{
	DIR *dir;
	struct dirent *dp;
	t_str_list *dlst;

	dlst = NULL;
	dir = opendir(name);
	if (dir == NULL) {
		return (dlst);
	}
	while (1) {
		dp = readdir(dir);
		if (dp == NULL)
			break;
		str_list_push(&dlst, ft_strdup(dp->d_name));
	}
	closedir(dir);
	return (dlst);
}
