#include "list.h"
#include <stdlib.h>

t_anytype
alloc_ex_token(t_expand_token_type token_type, char *str)
{
	t_anytype elem;
	elem.ex_token = (t_expand_token *)malloc(sizeof(t_expand_token));
	elem.ex_token->token_type = token_type;
	elem.ex_token->str = str;

	return (elem);

}
