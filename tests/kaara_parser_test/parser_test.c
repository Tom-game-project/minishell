
#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include <stdlib.h>

//make vtest TEST_FILE=tests/kaara_parser_test.c

void print(char *input);

int main(void)
{
    char *input = ft_strdup("hello \" \"hello\" \" >> outfile > outfile");
    print(input);
    return 0;
}


void print(char *input)
{
    if (input == NULL)
        return ;
    t_ast *ast;
    ast = allocation_ast();
    parser(ast, input);
    t_ast *current = ast;
    int idx = 0;
    printf("=== ASTの内容 ===\n");
    while (current != NULL)
    {
        printf("AST node %d:\n", idx);
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
