#include "parser.h"
#include <unistd.h>
#include <stdbool.h>
#include "test_tools.h"

//parseされたかを確認する。
//parseに失敗したらエラー出力しastは生成されずNULL。

bool parser_wrap2(t_ast **ast, char *input)
{
    if (e_result_paren_not_closed_err == parser(ast, input))
    {
        debug_dprintf(STDERR_FILENO, "minishell : parse error\n");
        return (false);
    }
    return (true);
}
