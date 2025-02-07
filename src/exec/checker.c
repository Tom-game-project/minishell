#include "exec.h"
#include "parser.h"

bool    check_logical_operator(t_ast *ast, int exit_status)
{
    if (ast->ctlope == e_ctlope_or && exit_status != 0)
        return (false);
    return (true);
}
