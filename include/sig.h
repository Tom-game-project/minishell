#ifndef SIG_H
#define SIG_H

/// シグナルを扱うグローバル変数
extern int g_signal_number;

void disable_ctrl_backslash();

/// STDINを閉じ、自身にEOFを送出する
void disconnect2stdin();
/// 一度閉じられたSTDINを復帰させる
void reconnect_stdin(int *exit_status);

void handle_sig(int sig);
void handle_sig2(int sig);

int sig_settig();

#endif
