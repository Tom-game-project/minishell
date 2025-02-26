
// # include "parser.h"

// t_parse_result  split_by_operater(t_ast *ast, char **str)
// {
//     t_parse_result result;
    

//     if (checker_str_ctl(*str))
//         next_input = separate_and_store_control_operators(ast, str);
//     else if (checker_str_pipe(*str))
//         next_input = separate_and_store_pipe_operators(ast, str);
//     else if (checker_str_rdt(*str))
//         next_input = separate_and_store_redirect_operators(ast, str);
//     else
//     {
//         result = separate_and_store_cmd_args(*ast, &str);
//         free(str);
//         return (result);
//     }
//     return (result);
// }