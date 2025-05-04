#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

volatile sig_atomic_t sigint_received = 0;  // SIGINT 受信フラグ

void handle_sigint(int signo) {
    (void)signo;
    sigint_received = 1;  // SIGINT 受信を記録
    printf("\n");  // 改行を入れてプロンプトを整える
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

int main() {
    int exit_status = 0;  // `main` 内のローカル変数
    char *input;

    // SIGINT のハンドラを設定
    signal(SIGINT, handle_sigint);

    while (1) {
        // SIGINT を受けたら exit_status を更新
        if (sigint_received) {  
            exit_status = 130;
            sigint_received = 0;
        }

        // exit_status を含むプロンプトを動的に生成
        char prompt[32];
        snprintf(prompt, sizeof(prompt), "[%d] >> ", exit_status);

        // ユーザー入力を取得
        input = readline(prompt);
        if (!input) {
            printf("Exiting with status: %d\n", exit_status);
            break;  // EOF (Ctrl-D) で終了
        }

        if (*input) {  // 空入力でなければ履歴に追加
            add_history(input);
        }

        printf("You entered: %s\n", input);
        free(input);
    }

    return exit_status;
}

