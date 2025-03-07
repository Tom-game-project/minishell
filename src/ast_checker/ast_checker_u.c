
#include "ast_checker.h"

bool is_enum_rdtope(t_operator ope)
{
    if (ope == e_ope_redirect_i)
        return (true);
    else if (ope == e_ope_redirect_o)
        return (true);
    else if (ope == e_ope_heredoc_i)
        return (true);
    else if (ope == e_ope_heredoc_o)
        return (true);
    return (false);
}
