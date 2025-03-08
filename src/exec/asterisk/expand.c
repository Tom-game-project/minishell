#include "expand_string.h"
#include "list.h"
#include "parser.h"
#include "path.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

t_str_list  *expand(char *input)
{
	char		*dir_path;
	t_str_list	*dir_list;

	dir_list = get_dir_list(".");

}

t_str_list search_dir_list(input)
{
    char		*dir_path;
	t_str_list	*dir_list;

    input
    dir_list = get_dir_list(dir_path);

    return (dir_list);
}