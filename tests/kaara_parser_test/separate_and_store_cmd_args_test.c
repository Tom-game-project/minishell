// make vtest TEST_FILE=tests/separate_and_store_cmd_args_test.c

#include "parser.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main(void)
{
    // 入力文字列を動的に確保

    char *input = ft_strdup("ls -la \"hello echo\" world ls -la");
    if (!input)
    {
        fprintf(stderr, "Input allocation error\n");
        return 1;
    }

    // ASTのルートノードを確保
    t_ast *ast = allocation_ast();

    // 入力文字列を解析してASTに格納する
    separate_and_store_cmd_args(ast, input);

    // ここからASTの内容を表示して確認する
    printf("=== ASTの内容 ===\n");
    t_ast *current = ast;
    int idx = 0;
    while (current != NULL)
    {
        printf("AST node %d:\n", idx);
        if (current->cmd != NULL)
            printf("  cmd      : %s\n", current->cmd);
        else
            printf("  cmd      : (null)\n");
        for (int i = 0; current->argv[i] != NULL; i++)
            printf("argv[%d] : %s\n",i,  current->argv[i]);
        printf("  ctlope   : ");
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
                printf("  ctlope   : ");
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
        current = current->right_ast;
        idx++;
    }

    // 必要なら、ASTの各ノードや input の解放処理を行う
    // （ここでは省略）

    return 0;
}