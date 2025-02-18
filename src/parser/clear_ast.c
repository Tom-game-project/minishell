#include "list.h"
#include "parser.h"
#include <stdlib.h>

void clear_ast(t_ast **ast)
{
    if ((*ast)->left_ast != NULL)
        clear_ast(&(*ast)->left_ast);
    if ((*ast)->right_ast != NULL)
        clear_ast(&(*ast)->right_ast);
    (*ast)->ope = e_ope_none;
    if ((*ast)->arg != NULL)
        str_list_clear(&(*ast)->arg, free);
    free(*ast);
    *ast = NULL;
}
