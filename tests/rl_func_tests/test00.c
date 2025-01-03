///
///
///
/// 自分の環境で
/// ```c
/// #include <readline/readline.h>
/// ```
/// が見つからないと言われた場合
///
/// ```bash
/// sudo apt update
/// sudo apt install libreadline-dev
/// ```
///
/// ## コンパイルの仕方
/// ```bash
/// gcc -o my_program my_program.c -lreadline
/// ```


#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
    char *input;

    while ((input = readline("Enter command: ")) != NULL) {
        if (*input) {  // 入力が空でない場合
            add_history(input);  // 入力を履歴に追加
        }
        printf("You entered: %s\n", input);
        free(input);  // `readline` の戻り値は動的に確保されたメモリを指す
    }
    return 0;
}
