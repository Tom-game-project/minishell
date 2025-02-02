#include "built_in.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define FILENAMEBUF 512

/// 現在のディレクトリを表示する
int show_cd()
{
	char filepath[FILENAMEBUF];

	memset(filepath, '\0', FILENAMEBUF);
	getcwd(filepath, FILENAMEBUF);
	printf("show cd %s\n", filepath);
	return (0);
}


/// cd のテスト
/// このテストは環境によって違うので目視で確認する必要がある
int main()
{
	int exit_status;

	// 相対パスの場合
	exit_status = built_in_cd("../");
	assert(exit_status == 0);
	show_cd();
	exit_status = built_in_cd("./minishell");
	assert(exit_status == 0);
	show_cd();
	// 絶対パスの場合
	exit_status = built_in_cd("/usr/bin/");
	assert(exit_status == 0);
	show_cd();
	// 不正なパスの場合
	// ## ファイルを指している場合
	exit_status = built_in_cd("/usr/bin/cc");
	assert(exit_status == 1);
	show_cd();
	// ## 存在しないファイルを指している場合
	exit_status = built_in_cd("aaaaaaaaaaaaaaaaaaa");
	assert(exit_status == 1);
	show_cd();
	// ## ファイル名が長すぎる場合
	exit_status = built_in_cd("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	assert(exit_status == 1);
	show_cd();
	return (0);
}
