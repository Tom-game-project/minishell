#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>



/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test01.c
/// ```
int main()
{
	//lst = split_path("/hello/world/this/is/tom");
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		is_same_string("aacgggfabfdddddc", "a*b*c")
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		is_same_string("hello.c", "*.c")
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		is_same_string("hello.rs", "*.c")
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		is_same_string("lslslslsls.hello.slslslslslslsls", "*.hello.*")
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		is_same_string("infile000", "infile*")
	);
	return (0);
}
