#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
 
#define SHADOW_FILEPATH    "./.minishell"
#define BUFFER_SIZE 100

/// 隠しファイルのfdを返却する　
int
create_shadow_file(char *pathname)
{
	int fd;

	fd = open(pathname, (O_RDWR | O_CREAT), 0664);
	if (fd < 0)
		return -1;
	if (unlink(pathname) < 0)
	{
		perror("unlink");
		close(fd);
		return -1;
	}
	return (fd);
}

/// ファイルの名前を与えると、
/// ファイルの情報を表示する
int 
show_file_stat(char *filepath)
{
  struct stat buf;
  int rebt = stat(filepath, &buf);
  printf("st_dev: %lu\n"
         "st_ino: %ld\n"
         "st_mode: %u\n"
         "st_nlink: %lu\n"
         "st_uid: %u\n"
         "st_gid: %d\n"
         "st_rdev: %lu\n"
         "st_size: %ld\n"
         "st_blksize: %ld\n"
         "st_blocks: %ld\n"
         "st_atime: %ld\n"
         "st_mtime: %ld\n"
         "st_ctime: %ld\n",
         buf.st_dev,
         buf.st_ino,
         buf.st_mode,
         buf.st_nlink,
         buf.st_uid,
         buf.st_gid,
         buf.st_rdev,
         buf.st_size,
         buf.st_blksize,
         buf.st_blocks,
         buf.st_atime,
         buf.st_mtime,
         buf.st_ctime);
  return (rebt);
}

/// ファイルのfdを与えると、
/// ファイルの情報を表示する
int 
show_file_fstat(int fd)
{
  struct stat buf;
  int rebt = fstat(fd, &buf);
  printf("st_dev: %lu\n"
         "st_ino: %ld\n"
         "st_mode: %u\n"
         "st_nlink: %lu\n"
         "st_uid: %u\n"
         "st_gid: %d\n"
         "st_rdev: %lu\n"
         "st_size: %ld\n"
         "st_blksize: %ld\n"
         "st_blocks: %ld\n"
         "st_atime: %ld\n"
         "st_mtime: %ld\n"
         "st_ctime: %ld\n",
         buf.st_dev,
         buf.st_ino,
         buf.st_mode,
         buf.st_nlink,
         buf.st_uid,
         buf.st_gid,
         buf.st_rdev,
         buf.st_size,
         buf.st_blksize,
         buf.st_blocks,
         buf.st_atime,
         buf.st_mtime,
         buf.st_ctime);
  return (rebt);
}

int
main(void) {
	int fd;
	int err;
	char str[BUFFER_SIZE] = "hello world";

	fd = create_shadow_file(SHADOW_FILEPATH);
	// 自プロセスからはアクセス可能
	// 他プロセスからはファイルが見えない

	write(fd, str, BUFFER_SIZE);
	// fd_write(fd,);
	printf("fd %d\n", fd);
	err = show_file_stat(SHADOW_FILEPATH); // 隠しファイルにすると、ファイルの名前からアクセスすることはできなそう。
							// 名前重複しないという点で重要かもしれない
	printf("err %d\n", err);
	err = show_file_fstat(fd);
	printf("err %d\n", err);
	close(fd); // ここでファイルの実態が削除される
	return 0;
}
 
