#include "sig.h"
#include "signal.h"
#include <stdlib.h>

/// イベントハンドラの設定
int sig_settig()
{
	struct sigaction sa_sigact;

	///シグナルハンドラの設定
	// Ctrl-\ (SIGQUIT) のための sigaction を設定
	sa_sigact.sa_handler = handle_sig;
	sigemptyset(&sa_sigact.sa_mask);
	sa_sigact.sa_flags = 0;
	sigaction(SIGQUIT, &sa_sigact, NULL);
	sigaction(SIGINT, &sa_sigact, NULL);
	disable_ctrl_backslash();
	return (0);
}
