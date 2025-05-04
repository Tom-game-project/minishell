#include "dict.h"
#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#include "expand_string.h"



// 古い方の関数、もう使わない
//bool func_wrap(char *str, char *rule_str) 
//{
//	t_char_list *c_lst;
//	t_str_list *rule_lst;
//	bool r;
//
//	c_lst = NULL;
//	char_list_push_str(&c_lst, str);
//	rule_lst = rule_to_lst(rule_str);
//	r = is_same_string(c_lst, rule_lst);
//	char_list_clear(&c_lst);
//	str_list_clear(&rule_lst, free);
//	return (r);
//}

void
free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}

bool func_wrap2(char *str, char *rule_str, t_str_dict *env)
{
	t_char_list *c_lst;
	//t_void_list *rule_lst;
	bool r;

	c_lst = NULL;
	char_list_push_str(&c_lst, str);
	
	t_void_list *token_list;
	token_list = expand_string2list2(rule_str, env);
	// あとで解放処理を入れる

	r = is_same_string(c_lst, token_list);
	char_list_clear(&c_lst);
	void_list_clear(&token_list, free_ex_token);
	return (r);
}


/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test01.c
/// ```
int main()
{

	t_str_dict *d;

	//char *str = "aaa$HELLO'$WORLD'$HELLOaaa|aaa";
	//char *str = "aaa'$WORLD'$HELLOaaa";
	//char *str = "\"*\"*'*'";
	//char *str = "???$HELLO$$?$?HELLO$?$WO";
	//char *str = "$$$";
	d = NULL;
	// 環境変数を模したもの
	str_dict_add(
		&d,
		ft_strdup("HELLO"),
		ft_strdup("HELLO_VALUE"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("$"),
		ft_strdup("PID"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("?"),
		ft_strdup("EXIT STATUS"), 
		free
	);

	//lst = split_path("/hello/world/this/is/tom");
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("aacgggfabfdddddc", "a*b*c", d)
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("aacgggfabfdddddc", "*a*b*c*", d)
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("hello.c", "*.c", d)
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("hello.rs", "*.c", d)
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("lslslslsls.hello.slslslslslslsls", "*.hello.*", d)
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("infile000", "infile*", d)
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("#*message*-20250126-122009#", "*'*'*", d)
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap2("#message-20250126-122009#", "*'*'*", d)
	);
	str_dict_clear(&d, free, free);
	return (0);
}
