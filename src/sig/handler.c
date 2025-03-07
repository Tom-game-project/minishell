#include <signal.h>
#include <sig.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>

#include "sig.h"

void handle_sig(int sig)
{
	g_signal_number = sig;
	if (sig == SIGINT)
	{
		rl_on_new_line();      // 新しい行を準備
		rl_replace_line("", 0);// 入力行をクリア
		disconnect2stdin();
	}
}
