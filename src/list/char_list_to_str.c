#include "list.h"
#include <stdlib.h>


/// 与えられたnodeを文字列にする
char *char_list_to_str(t_char_list *node)
{
	char *rstr;
	char *rstr_tmp;

	rstr = (char *) malloc(sizeof(char) * char_list_len(node) + 1);
	rstr_tmp = rstr;
	if (rstr == NULL)
		return (NULL);
	while (node != NULL)
	{
		*rstr = node->ptr.c;
		node = node->next;
		rstr++;
	}
	*rstr = '\0';
	return (rstr_tmp);
}
