#!/bin/bash

# 使い方
#
# ```bash
# ./check_dependency.sh <実行可能バイナリ>
# ```

# 許可された関数のリスト
ALLOWED_FUNCTIONS=("readline" "rl_clear_history" "rl_on_new_line" "rl_replace_line" "rl_redisplay" "add_history" "printf" "malloc" "free" "write" "access" "open" "read" "close" "fork" "wait" "waitpid" "wait3" "wait4" "signal" "sigaction" "sigemptyset" "sigaddset" "kill" "exit" "getcwd" "chdir" "stat" "lstat" "fstat" "unlink" "execve" "dup" "dup2" "pipe" "opendir" "readdir" "closedir" "strerror" "perror" "isatty" "ttyname" "ttyslot" "ioctl" "getenv" "tcsetattr" "tcgetattr" "tgetent" "tgetflag" "tgetnum" "tgetstr" "tgoto" "tputs")

# 監視するバイナリ
TARGET_BINARY="$1"

if [ -z "$TARGET_BINARY" ]; then
    echo "Usage: $0 <binary>"
    exit 1
fi

# nm で外部シンボルを取得（`U` でマークされた関数）
UNUSED_SYMBOLS=$(nm -u "$TARGET_BINARY" | awk '$1 == "U" {print $2}' | cut -d'@' -f1)

# echo TARGET_BINARY $TARGET_BINARY

echo 見つかった関数
echo $UNUSED_SYMBOLS

if [ -z "$UNUSED_SYMBOLS" ]; then
    echo "No undefined symbols found."
    exit 0
fi

# 許可されていない関数を抽出
for symbol in $UNUSED_SYMBOLS; do
    if ! [[ " ${ALLOWED_FUNCTIONS[*]} " =~ " $symbol " ]]; then
        echo "WARNING: Unauthorized function detected: $symbol"
    fi
done

