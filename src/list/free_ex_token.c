
#include "list.h"
#include <stdlib.h>

void	free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}
