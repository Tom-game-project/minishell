#include "libft.h"
#include "parser.h"
#include <stdlib.h>

void	parser(t_ast **ast, char *input)
{
	char *str;

	str = ft_strdup(input);
	*ast = allocation_ast();
	if (checker_str_ctl(input))
		separate_and_store_control_operators(*ast, &str);
	else if (checker_str_rdt(input))
		separate_and_store_redirect_operators(*ast, &str);
	else
		separate_and_store_cmd_args(*ast, &str);
}
