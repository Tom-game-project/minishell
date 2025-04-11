#include "libft.h"
#include "list.h"

#include <stdlib.h>
#include <limits.h>

// prompt
//
char	*prompt(int exit_status)
{
	char		buf[PATH_MAX];
	char		*exit_str;
	t_char_list	*rstr_list;
	char		*rstr;

	exit_str = ft_itoa(exit_status);
	rstr_list = NULL;
	if (getcwd(buf, PATH_MAX) != NULL)
		char_list_push_str(&rstr_list, buf);
	char_list_push_str(&rstr_list, " [");
	char_list_push_str(&rstr_list, exit_str);
	char_list_push(&rstr_list, ']');
	char_list_push_str(&rstr_list, "> ");
	rstr = char_list_to_str(rstr_list);
	char_list_clear(&rstr_list);
	free(exit_str);
	return (rstr);
}
