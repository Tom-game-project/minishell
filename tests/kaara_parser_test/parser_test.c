
#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include <stdlib.h>

//make vtest TEST_FILE=tests/kaara_parser_test.c

void print(t_ast *ast);


int main(void)
{
    char *input = ft_strdup("hello hello");
    t_ast *ast;

    ast = NULL;
    parser(&ast, input);
    print(ast);
    free(input);
    return 0;
}


void print(t_ast *ast)
{
    t_ast *current = ast;
    int idx = 0;
    printf("=== ASTの内容 ===\n");
    while (current != NULL)
    {
        printf("=======AST node %d=======\n", idx);
        if (current->cmd != NULL)
            printf("cmd      : %s\n", current->cmd);
        else
            printf("cmd      : (null)\n");
        printf(" ---- arg ---- \n");
        if (current->arg != NULL)
		    str_list_print(current->arg);
        else
            printf("arg : (null)\n");
        printf("ctlope : ");
        switch (current->ctlope)
        {
            case e_ctlope_and:
                printf("&&\n");
                break;
            case e_ctlope_or:
                printf("||\n");
                break;
            default:
                printf("NONE\n");
                break;
        }
        printf("rdtope : ");
        switch (current->rdtope)
        {
            case e_rdtope_redirect_i:
                printf("<\n");
                break; 
            case e_rdtope_redirect_o:
                printf(">\n");
                break;
            case e_rdtope_heredoc_i:
                printf("<<\n");
                break;
            case e_rdtope_heredoc_o:
                printf(">>\n");
                break ;
            case e_rdtope_pipe:
                printf("|\n");
                break;            
            default:
                printf("NONE\n");
                break;
        }
        current = current->right_ast;
        idx++;
    }
}
