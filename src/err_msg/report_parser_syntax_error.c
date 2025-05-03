#include "libft.h"

int report_parser_syntax_error(void)
{
	ft_putstr_fd("minishell : parser : syntax error\n", STDERR_FILENO);
	return (1);
}
