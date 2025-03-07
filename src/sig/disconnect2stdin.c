#include <unistd.h>
#include <fcntl.h>

/// STDINを閉じて、EOFを送る関数
///
/// Ctrl-Dと同様の効果が得られる
void disconnect2stdin()
{
	int devnull;

	devnull = open("/dev/null", O_RDONLY);
	dup2(devnull, STDIN_FILENO);  // 標準入力を /dev/null にリダイレクト
	close(devnull); // stdinを閉じて、EOFを送る
}
