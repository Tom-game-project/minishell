#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define MAX_LEN 1024

void enable_raw_mode(struct termios *orig_termios) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, orig_termios);
    raw = *orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // カノニカルモードを無効化
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw_mode(struct termios *orig_termios) {
    tcsetattr(STDIN_FILENO, TCSANOW, orig_termios);
}

void custom_prompt() {
    struct termios orig_termios;
    enable_raw_mode(&orig_termios);

    char buffer[MAX_LEN] = {0};
    int index = 0;

    printf("Custom Prompt> ");
    fflush(stdout);

    while (1) {
        char c;
        if (read(STDIN_FILENO, &c, 1) <= 0) {
            break;
        }

        // Ctrl-D (EOF) が押された場合の処理
        if (c == 4) { 
            if (index == 0) { 
                printf("\n[Exit]\n");
                break;  // 何も入力がなければ終了
            }
            // 途中まで入力があるなら無視して続行
            continue;
        }

        // Backspace (127) の処理
        if (c == 127 || c == 8) {
            if (index > 0) {
                buffer[--index] = '\0';
                printf("\b \b"); // 1 文字削除
                fflush(stdout);
            }
            continue;
        }

	if (c == '\n')
	{
		printf("\nbuffer %s\n", buffer);
		    printf("Custom Prompt> ");
	}

        // 通常の文字をバッファに追加
        if (index < MAX_LEN - 1) {
            buffer[index++] = c;
            buffer[index] = '\0';
            putchar(c);
            fflush(stdout);
        }
    }

    disable_raw_mode(&orig_termios);
}

int main() {
    custom_prompt();
    return 0;
}

