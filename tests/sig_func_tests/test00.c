#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigusr1(int sig) {
    printf("Caught signal %d (SIGUSR1)\n", sig);
}

int main() {
    struct sigaction sa;
    sigset_t set;

    // シグナルセットを初期化
    sigemptyset(&set);
    sigaddset(&set, SIGINT); // SIGINT をブロック対象に追加

    // シグナル処理関数を設定
    sa.sa_handler = handle_sigusr1;
    sa.sa_mask = set; // SIGUSR1 処理中に SIGINT をブロック
    sa.sa_flags = 0;

    // SIGUSR1 に対する処理を設定
    sigaction(SIGUSR1, &sa, NULL);

    printf("Send SIGUSR1 to this process (PID: %d)\n", getpid());
    while (1) {
        sleep(1); // 無限ループ
    }
    return 0;
}
