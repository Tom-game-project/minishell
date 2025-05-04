#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

void check_path(const char *path) {
    struct stat path_stat;

    // lstat() を使ってリンクそのものの情報を取得
    if (lstat(path, &path_stat) != 0) {
        perror("lstat");
        return;
    }

    // シンボリックリンクかどうかを判定
    if (S_ISLNK(path_stat.st_mode)) {
        printf("%s is a symbolic link.\n", path);

        // リンクの実体を取得
        if (stat(path, &path_stat) != 0) {
            perror("stat");
            return;
        }
    }

    // ファイル or ディレクトリの判定
    if (S_ISREG(path_stat.st_mode)) {
        printf("%s is a regular file.\n", path);
    } else if (S_ISDIR(path_stat.st_mode)) {
        printf("%s is a directory.\n", path);
    } else {
        printf("%s is some other type.\n", path);
    }
}

/// ```bash
/// make example EXAMPLE_FILE=examples/stat_example00.c
/// ```
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    check_path(argv[1]);
    return 0;
}

