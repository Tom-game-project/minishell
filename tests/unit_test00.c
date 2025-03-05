
/// 体系的なテストを実行する
#include "dict.h"
#include "loop.h"
#include <stdlib.h>
#include "libft.h"

int cmd_test(int argc, char *argv[], char *envp[], char *str)
{
	(void) argc;
	(void) argv;
	int exit_status;

	t_str_dict *d;
	d = NULL;
	envp_to_str_dict(&d, envp);
	//str_dict_add(
	//	&d,
	//	ft_strdup("?"),
	//	ft_itoa(0),
	//	free
	//);
	exit_status = exec_shell_cmd(str, &d);
	str_dict_clear(&d, free, free);
	return (exit_status);
}




/// # unit_test00
///
///
/// ```bash
/// make vtest TEST_FILE=tests/unit_test00.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	cmd_test(argc, argv, envp, "< infile");
	cmd_test(argc, argv, envp, "< infile cat| head");
	cmd_test(argc, argv, envp, "echo hello | < infile cat");
	cmd_test(argc, argv, envp, "echo hello | < infile cat | head");
	cmd_test(argc, argv, envp, "< infile cat | cat | cat | cat");
	cmd_test(argc, argv, envp, "echo hello world | < infile cat && cat < infile");
	cmd_test(argc, argv, envp, "echo hello world | < infile cat || cat < infile");


	//cmd_test(argc, argv, envp, "<< EOF cat | head");
	//cmd_test(argc, argv, envp, "echo hello world | cat | << EOF cat ");
	//cmd_test(argc, argv, envp, "echo hello world |<< EOF cat | cat");
	//cmd_test(argc, argv, envp, "echo hello world | << EOF cat");
	//cmd_test(argc, argv, envp, "echo hello world | << EOF cat && cat << EOF");

	
	//cmd_test(argc, argv, envp, "sssssssssssssssssss| sssssssssssssss | echo hello");

	return (0);
}
