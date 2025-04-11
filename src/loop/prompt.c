#include "libft.h"
#include "list.h"

#include <stdlib.h>
#include <limits.h>


static void error_color(t_char_list *lst, int exit_status)
{
	char *exit_str;

	exit_str = ft_itoa(exit_status);
	if (exit_status == 0)
		char_list_push_str(&lst, "\e[32m [");
	else 
		char_list_push_str(&lst, "\e[31m [");
	char_list_push_str(&lst, exit_str);
	char_list_push_str(&lst, "]\e[m");
	free(exit_str);
}


// prompt
//
char	*prompt(int exit_status)
{
	char		buf[PATH_MAX];
	t_char_list	*rstr_list;
	char		*rstr;

	rstr_list = NULL;
	if (getcwd(buf, PATH_MAX) != NULL)
		char_list_push_str(&rstr_list, buf);
	error_color(rstr_list, exit_status);
	char_list_push_str(&rstr_list, "> ");
	rstr = char_list_to_str(rstr_list);
	char_list_clear(&rstr_list);
	return (rstr);
}
