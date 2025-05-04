#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

struct termios orig_termios;

void disable_ctrl_backslash() {
    struct termios new_termios;
    tcgetattr(0, &orig_termios); // 現在の端末設定を取得
    new_termios = orig_termios;
    new_termios.c_cc[VQUIT] = _POSIX_VDISABLE; // `Ctrl-\` を無効化
    tcsetattr(0, TCSANOW, &new_termios);
}

void restore_terminal() {
    tcsetattr(0, TCSANOW, &orig_termios); // 元の設定に戻す
}

int main() {
    // `Ctrl-\` (SIGQUIT) を無視する
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGQUIT, &sa, NULL);

    disable_ctrl_backslash(); // `Ctrl-\` のエコーを防ぐ

    while (1) {
        char *input = readline(">> ");
        if (!input) break; // EOF (Ctrl-D) を検出
        printf("You entered: %s\n", input);
        free(input);
    }

    restore_terminal(); // 終了時に端末設定を元に戻す
    return 0;
}

