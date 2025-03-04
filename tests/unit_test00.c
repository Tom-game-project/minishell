
/// 体系的なテストを実行する
#include "dict.h"
#include "loop.h"
#include <stdlib.h>

int cmd_test(int argc, char *argv[], char *envp[], char *str)
{
	(void) argc;
	(void) argv;

	t_str_dict *d;
	d = NULL;
	envp_to_str_dict(&d, envp);
	exec_shell_cmd(str, &d);
	str_dict_clear(&d, free, free);
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
	// cmd_test(argc, argv, envp, "< infile");
	//cmd_test(argc, argv, envp, "< infile cat| head");
	//cmd_test(argc, argv, envp, "< infile cat | cat | cat | cat");
	cmd_test(argc, argv, envp, "<< EOF cat | head");
	// cmd_test(argc, argv, envp, "echo hello world | << EOF cat | head");
	return (0);
}
