#include "ast_checker.h"
#include "parser.h"
#include <unistd.h>

bool ast_checker_wrap2(t_ast **ast)
{
    t_syntax_result result;

    result = ast_checker(*ast);
    if (result == e_syntax_ok)
        return (true);
    if (result != e_syntax_ok && result != e_no_input)
        print_checker_result(result);
    clear_ast(ast);
    *ast = NULL;
    return (false);
}