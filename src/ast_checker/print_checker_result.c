#include "ast_checker.h"
#include "test_tools.h"
#include <unistd.h>

/// TODO 書き換える！！！
bool    print_checker_result(t_syntax_result result)
{
    if (result == e_syntax_ok)
        return (true);
    else if (result == e_ctl_near_unexpected_token_and)
        debug_dprintf(STDERR_FILENO, "minishell : near_unexpected_token_and\n");
    else if (result == e_ctl_near_unexpected_token_or)
        debug_dprintf(STDERR_FILENO,"minishell : near_unexpected_token_or\n");
    else if (result == e_rdt_near_unexpected_token_pipe)
        debug_dprintf(STDERR_FILENO,"minishell : near_unexpected_token_pipe\n");
    else if (result == e_rdt_near_unexpected_token_newline)
        debug_dprintf(STDERR_FILENO, "minishell : near_unexpected_token_newline\n");
    else if (result == e_rdt_near_unexpected_token_rdt)
        debug_dprintf(STDERR_FILENO, "minishell : near_unexpected_token_rdt\n");
    else if (result == e_syntax_near_unexpected_token_string)
        debug_dprintf(STDERR_FILENO, "minishell : near_unexpected_token_string\n");
    return (false);
}
