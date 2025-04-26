
#include "ast_checker.h"

bool is_enum_rdtope(t_operator ope)
{
    return (
		ope == e_ope_redirect_i ||
		ope == e_ope_redirect_o ||
		ope == e_ope_heredoc_i ||
		ope == e_ope_heredoc_o
	);
}
