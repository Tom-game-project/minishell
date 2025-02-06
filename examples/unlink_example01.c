#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define SHADOW_FILE_NAME "./.minishell"
#define BUFFER_SIZE 1024


/// # dupを使い新しいファイルディスクリプタを生成
///
/// dupは使われていない整数をファイルディスクリプタとして割り当てる
int main()
{
    int fd, fd_read, no_fd;
    char buf[BUFFER_SIZE];
    size_t n;

    // **ファイルをO_RDWR（読み書き可能）でオープン**
    fd = open(SHADOW_FILE_NAME, O_RDWR | O_CREAT, 0644);
    no_fd = open("results.txt", O_RDWR | O_CREAT, 0644);
    printf("fd %d \n", fd);
    if (fd == -1)
    {
        printf("could not open the file\n");
        return (1);
    }

    // **データを書き込む**
    write(fd, "helloworld", 10);

    // **dup() を使って、新しいファイルディスクリプタを作成**
    // >>>>>>>> ここから
    fd_read = dup(fd);
    printf("new_fd %d \n", fd_read);
    if (fd_read == -1)
    {
        printf("could not duplicate file descriptor\n");
        close(fd);
        return (1);
    }
    
    // **新しいファイルディスクリプタを読み込み専用で開き直す**
    close(fd_read); // まずクローズ
    // <<<<<<<< ここまで
    fd_read = open(SHADOW_FILE_NAME, O_RDONLY);
    if (fd_read == -1)
    {
        printf("could not open the file for reading\n");
        close(fd);
        return (1);
    }

    // **バッファをクリアしてから読み込む**
    memset(buf, '\0', BUFFER_SIZE);
    n = read(fd_read, buf, BUFFER_SIZE - 1);
    buf[n] = '\0';

    printf("file contents:%lu: %s\n", n, buf);

    // **ファイルディスクリプタを閉じる**
    close(fd);
    close(fd_read);
    close(no_fd);
    return (0);
}

