/// 体系的なテストを実行する
#include "dict.h"
#include "loop.h"
#include "libft.h"
#include "envtools.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cmd_test(int argc, char *argv[], char *envp[], char *str)
{
	(void) argc;
	(void) argv;
	int exit_status;

	t_str_dict *d;
	d = NULL;
	envp_to_str_dict(&d, envp);
	str_dict_add(
                &d,
                ft_strdup("?"),
                ft_itoa(0),
                free
        );
	exit_status = 0;
	exec_shell_cmd(str, &d, &exit_status);
	update_exit_status(exit_status, &d);
	str_dict_clear(&d, free, free);
	return (exit_status);
}

/// パイプ関係のテスト
int test00(int argc, char *argv[], char *envp[])
{
	cmd_test(argc, argv, envp, "< infile");
	cmd_test(argc, argv, envp, "< infile cat | head");
	cmd_test(argc, argv, envp, "echo hello | < infile cat");
	cmd_test(argc, argv, envp, "echo hello | < infile cat | head");
	cmd_test(argc, argv, envp, "< infile cat | cat | cat | cat");
	cmd_test(argc, argv, envp, "echo hello world | < infile cat && cat < infile");
	cmd_test(argc, argv, envp, "echo hello world | < infile cat || cat < infile");
	cmd_test(argc, argv, envp, "sed -ne < infile '$='");
	return (0);
}

/// アンド演算子関係のテスト
int test01(int argc, char *argv[], char *envp[])
{
	cmd_test(argc, argv, envp, "< infile");
	cmd_test(argc, argv, envp, "< infile cat & head");
	cmd_test(argc, argv, envp, "echo hello && < infile cat");
	cmd_test(argc, argv, envp, "echo hello && < infile cat | head");
	cmd_test(argc, argv, envp, "< infile cat && cat & cat | cat");
	cmd_test(argc, argv, envp, "echo hello world && < infile cat && cat < infile");
	cmd_test(argc, argv, envp, "echo hello world && < infile cat || cat < infile");
	cmd_test(argc, argv, envp, "sed -ne < infile '$='");
	cmd_test(argc, argv, envp, "< minishell cat  | sha256sum  | awk '{print $1}' >> outfile");
	return (0);
}

/// or演算子関係のテスト

/// 追記リダイレクト関係のテスト
int test02(int argc, char *argv[], char *envp[])
{
	// バイナリを正しくパイプできているかを確かめている
	cmd_test(argc, argv, envp, "< minishell cat  | sha256sum  | awk '{print $1}' > outfile1");
	cmd_test(argc, argv, envp, "sha256sum minishell | awk '{print $1}' > outfile2");
	cmd_test(argc, argv, envp, "diff outfile1 outfile2 | wc -l"); // 正しく実行できていれば0が表示される
	return (0);
}

/// # unit_test00
///
///
/// ```bash
/// make vtest TEST_FILE=tests/unit_test00.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	//test00(argc, argv, envp);
	//test01(argc, argv, envp);
	//test02(argc, argv, envp);

	// heredocを除くredirectのテスト
	// heredocは、fdはvalgrindを通すと、fdを閉じていないみたいなエラーが出るけど多分問題ない
	// 親で開いたfdがfork時にも複製されるおそらくそれを閉じれていないだけ
	// 余裕があれば閉じたいが、exitで勝手に閉じる+ 実行中にリソースを食いつぶすタイプの疾患ではない
	//
	//cmd_test(argc, argv, envp, "<< EOF cat | head");
	cmd_test(argc, argv, envp, "echo hello world | cat | << EOF cat ");
	//cmd_test(argc, argv, envp, "echo hello world |<< EOF cat | cat");
	//cmd_test(argc, argv, envp, "echo hello world | << EOF cat");
	//cmd_test(argc, argv, envp, "echo hello world | << EOF cat && cat << EOF");

	//cmd_test(argc, argv, envp, "sssssssssssssssssss| sssssssssssssss | echo hello");
	return (0);
}
