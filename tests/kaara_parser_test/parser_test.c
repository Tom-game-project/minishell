
#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include <stdlib.h>
#include "../tests/tom_parser_tools/tools.h"

//make vtest TEST_FILE=tests/kaara_parser_test/parser_test.c

void print(t_ast *ast, int i);


int main(void)
{
    char *input = ft_strdup("((echo hello < infile) || ls -la) && grep .c");
    t_ast *ast;
    ast = NULL;
    parser(&ast, input);
    print_ast(ast, 0);
    clear_ast(ast);
    free(ast);
    free(input);
    return 0;
}

// void print(t_ast *ast, int i)
// {
//     t_ast *current = ast;

//     printf("=== %d : ASTの内容 ===\n", i);
//     printf(" ---- arg ---- \n");
//     if (current->arg == NULL)
//         printf("arg : (null)\n");
//     else
//     {
//         str_list_print(current->arg);
//         return ;
//     }
//     printf("op : ");
//     switch (current->ope)
//     {
//         case e_ope_and:
//             printf("&&\n");
//             break;
//         case e_ope_or:
//             printf("||\n");
//             break;
//             case e_ope_redirect_i:
//             printf("<\n");
//             break; 
//         case e_ope_redirect_o:
//             printf(">\n");
//             break;
//         case e_ope_heredoc_i:
//             printf("<<\n");
//             break;
//         case e_ope_heredoc_o:
//             printf(">>\n");
//             break ;
//         case e_ope_pipe:
//             printf("|\n");
//             break;
//         case e_ope_paren:
//             printf(")\n");
//             break;
//         default:
//             printf("NONE\n");
//             break;
//     }
//     i++;
//     print(current->left_ast, i);
//     print(current->right_ast, i);
//     return ;
// }
