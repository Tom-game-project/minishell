#include "parser.h"
#include <assert.h>

/// make vtest TEST_FILE=tests/tom_parser_test/tom_syntax_checker.c
int main()
{
	//bool a;
	
	// ok case
	assert (syntax_checker2("ls -la"));
	assert (syntax_checker2("(ls -la)"));
	assert (syntax_checker2("((ls -la))"));
	assert (syntax_checker2("(ls -la) | (grep src)"));
	assert (syntax_checker2("(ls -la) | (grep \"src\")"));
	assert (syntax_checker2("echo '('\"(\"'('"));
	// ko case
	assert (!syntax_checker2("(ls -la"));
	assert (!syntax_checker2("ls -la)"));
	assert (!syntax_checker2("((ls -la)"));
	assert (!syntax_checker2("(ls -la))"));
	assert (!syntax_checker2("(ls -la) | grep src)"));
	assert (!syntax_checker2("(ls -la) | (grep src"));
	assert (!syntax_checker2("(ls -la | (grep \"src\")"));
	assert (syntax_checker2("echo '('\"(\"'("));
	return (0);
}
