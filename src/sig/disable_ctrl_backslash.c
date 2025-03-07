#include <termios.h>
#include <unistd.h>

/// # disable_ctrl_backslash
///
/// `ctrl-\`を無効化する関数
void disable_ctrl_backslash() 
{
	struct termios orig_termios;
	struct termios new_termios;

	tcgetattr(STDIN_FILENO, &orig_termios); // 現在の端末設定を取得
	new_termios = orig_termios;
	new_termios.c_cc[VQUIT] = _POSIX_VDISABLE; // `Ctrl-\` を無効化
	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}


