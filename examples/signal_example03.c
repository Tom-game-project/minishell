#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_eof(int sig) {
    // Ctrl+Dが押されたときにプロンプトを終了
    printf("\nCtrl+D pressed. Exiting...\n");
    exit(0);
}

int main() {
    char buffer[256];

    // SIGINT（Ctrl+C）やEOF（Ctrl+D）に対してシグナルハンドラを設定
    struct sigaction sa;
    sa.sa_handler = handle_eof;      // EOFの場合に呼び出すハンドラ関数
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);        // 他のシグナルはマスクしない

    // SIGINTとSIGQUITをEOFに置き換えて処理する
    sigaction(SIGINT, &sa, NULL);   // Ctrl+Cが押されたときの処理
    sigaction(SIGQUIT, &sa, NULL);  // Ctrl+\が押されたときの処理

    while (1) {
        // ユーザーから入力を受け取る
        printf("Enter something (Ctrl+D to exit): ");
        
        // 標準入力から1行読み取る
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Ctrl+Dが押されるとEOFが返る
	    printf("\n");
	    printf("exit\n");
            // ここではEOFが押されたときに終了する
            break;
        }

        // 入力内容を表示
        printf("You entered: %s", buffer);
    }

    return 0;
}

