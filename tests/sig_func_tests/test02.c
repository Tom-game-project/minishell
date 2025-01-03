#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT (Ctrl-C), Signal number: %d\n", sig);
    // プログラムを終了する場合
    // exit(0);
}

void handle_sigquit(int sig) {
    printf("Caught SIGQUIT (Ctrl-\\), Signal number: %d\n", sig);
}

void handle_sighup(int sig) {
    printf("Caught SIGHUP (Ctrl-D), Signal number: %d\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa_sigint, sa_sigquit, sa_sighup;

    // Ctrl-C (SIGINT) のための sigaction を設定
    sa_sigint.sa_handler = handle_sigint;
    sigemptyset(&sa_sigint.sa_mask); // 他のシグナルをブロックしない
    sa_sigint.sa_flags = 0;
    sigaction(SIGINT, &sa_sigint, NULL);

    // Ctrl-\ (SIGQUIT) のための sigaction を設定
    sa_sigquit.sa_handler = handle_sigquit;
    sigemptyset(&sa_sigquit.sa_mask);
    sa_sigquit.sa_flags = 0;
    sigaction(SIGQUIT, &sa_sigquit, NULL);

    // Ctrl-D (SIGHUP) のための sigaction を設定
    sa_sighup.sa_handler = handle_sighup;
    sigemptyset(&sa_sighup.sa_mask);
    sa_sighup.sa_flags = 0;
    sigaction(SIGHUP, &sa_sighup, NULL);

    printf("Press Ctrl-C, Ctrl-\\, or Ctrl-D to test signal handling.\n");

    while (1) {
        pause();  // シグナルを待つ
    }

    return 0;
}

