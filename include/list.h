#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef union u_anytype t_anytype;

// expand string 専用
typedef enum e_expand_token t_expand_token_type;

enum e_expand_token
{
	e_word,
	e_asterisk
};

typedef struct s_expand_token t_expand_token;

struct s_expand_token
{
	t_expand_token_type token_type;
	char *str;
};


// listで扱いたい型
typedef struct s_void_list t_void_list;

union  u_anytype
{
	int i32;
	char c;
	char *str;
	t_expand_token *ex_token;
	t_void_list *list; // 二次元リスト
};

/// void ptrを格納するリスト
/// 拡張性,抽象度を上げるために定義した構造体
///
/// この構造体はすべてのリストのベース
struct s_void_list
{
	t_anytype ptr;
	t_void_list *next;
};

/// ================ 拡張 ================
/// すべてのlistのベースは`s_void_list`

/// charを格納するリスト
typedef struct s_void_list t_char_list;

/// strを格納するリスト
typedef struct s_void_list t_str_list;

/// intを格納するリスト
typedef struct s_void_list t_int_list;

/// ================ 実装 ================
/// 格納するデータtypeによらない操作の実装は、void_listをwrapしている

/// ================ char_list functions ================

t_char_list *init_char_list(char c);

int char_list_push(t_char_list **node, char c);

int char_list_push_str(t_char_list **node, char *str);

char char_list_pop(t_char_list **node, int index);

char	char_list_get_elem(t_char_list *node, int index);

t_str_list *str_list_get_back(t_str_list *node);

int	char_list_len(t_char_list *node);

int char_list_print(t_char_list *node);

int	char_list_insert(t_char_list **node, int index, char c);

int char_list_insert_str(t_char_list **node, int index,char *str);

int char_list_clear(t_char_list **node);

char *char_list_to_str(t_char_list *node);

bool char_list_is_empty(t_char_list *node);

int char_list_search_index(t_char_list *node, bool (*f)(char *));

t_str_list *char_list_cut(t_char_list **node, int index);


bool char_list_startswith(t_char_list *lst, char *str);

bool char_list_endswith(t_char_list *lst, char *str);

/// ================ str_list functions ================

char *candy_cutter(t_str_list **lst, int index);

t_str_list *init_str_list(char *str);

int str_list_push(t_str_list **node, char *str);

int str_list_print(t_str_list *node);

int str_list_len(t_str_list *node);

char *str_list_pop(t_str_list **node, int index);

int str_list_clear(t_str_list **node, void (*f)(void *));

char *str_list_to_str(t_str_list *node);

char **str_list_to_array(t_str_list *node);

char *str_list_join(t_str_list *node, char *sep);

t_str_list *str_list_get_ptr(t_str_list *head, int index);

t_str_list *str_list_split(char *str, char c);

int str_list_map(t_str_list **node, char *(*f)(char *));

char *str_list_search(t_str_list *node, bool (*f)(char *));

int str_list_search_index(t_str_list *node, bool (*f)(char *));

int str_list_search_index_r(t_str_list *node, bool (*f)(char *));

t_str_list *str_list_search_node(t_str_list *node, bool (*f)(char *, char *), char *str);

int str_list_map_arg1(t_str_list **node, char *(*f)(char *, void *), void *arg);

char *str_list_get_elem(t_str_list *node, int index);

int str_list_concat(t_str_list **a, t_str_list *b);

t_str_list *str_list_clone(t_str_list *a, char *(*f)(char *));

t_str_list *str_list_cut(t_str_list **node, int index);

bool str_list_in(char *str, t_str_list *lst);

int str_list_trim(t_str_list **lst, t_str_list *set, void(*f)(void *));
/// ================ int_list functions ================

t_int_list *init_int_list(int i);

int int_list_push(t_int_list **node, int i);

int int_list_len(t_int_list *node);

int int_list_clear(t_int_list **node);

int int_list_print(t_int_list *node);

int int_list_pop(t_int_list **node, int index);

int int_list_insert(t_int_list **node, int index, int i);


/// ================ token_list functions ================

t_anytype
alloc_ex_token(t_expand_token_type token_type, char *str);

t_void_list *token_list_clone(t_void_list *lst, t_anytype (*f)(t_anytype));

char *token_list_join(t_void_list *lst);

/// ================ void_list functions ================

int list_list_print(t_void_list *list, int (*print)(int, t_anytype));

/// ================ void_list functions ================
///
/// 格納するデータのtypeによらないlistそのものの実装は以下の関数に定義されている.
///

t_void_list *void_list_init(t_anytype ptr);

t_void_list *void_list_get_back(t_void_list *node);

int void_list_push(t_void_list **node, t_anytype ptr);

int void_list_concat(t_void_list **a, t_void_list *b);

int void_list_clear(t_void_list **node, void (*f)(t_anytype));

t_void_list *
void_list_cut(t_void_list **node, int index);

int void_list_clear_func(t_void_list **node, void (*func)(t_anytype, void (*g)(void *)), void(*f)(void *));

/// map

int void_list_map(
		t_void_list **node,
	       	t_anytype (*func)(t_anytype, void *(*g)(void *)),
	       	void *(*f)(void *)
);

int void_list_map_arg1(
		t_void_list **node,
	       	t_anytype (*func)(t_anytype, void *(*g)(void *, void *), void *),
	       	void *(*f)(void *, void *),
		void *arg
);

int void_list_pop(t_void_list **node, int index, t_anytype *rvalue);

int void_list_len(t_void_list *node);

int void_list_print(t_void_list *node, int (*print)(int, t_anytype));

t_void_list *void_list_get_elem(t_void_list *node, int index);

int void_list_insert(t_void_list **node, int index, t_anytype elem);

/// search

int void_list_search(
	t_void_list *node,
       	bool (*func)(
		t_anytype,
		bool (*g)(void *)), 
	bool (*f)(void *),
       	t_anytype *rvalue
);

int void_list_search_index(
	t_void_list *node, 
	bool (*func)(
		t_anytype,
		bool (*g)(void *)),
       	bool (*f)(void *)
);

int	void_list_search_index_r(
	t_void_list *node, \
	bool (*func)(
		t_anytype,
		bool (*g)(void *)), \
	bool (*f)(void *)
);

int void_list_search2_index(
	t_void_list *node,
	bool (*func)(
		t_anytype, 
		bool (*g)(void *, void *), 
		void *), 
	bool (*f)(void *, void *),
	void *str
);

int merge_sort(t_void_list **node, bool (*cmp)(t_anytype, t_anytype));

int void_list_insert_list(
	t_void_list **target,
	t_void_list *lst,
       	int index
);


t_void_list *void_list_filter(
	t_void_list **node,
	bool (*f)(t_anytype)
);

t_void_list *void_list_filter2(
	t_void_list **node,
	bool (*f)(t_anytype, t_anytype),
	t_anytype arg
);

// TODO for test
// 以下の関数は、成果物に含めない
//

int str_list_dprint(int fd, t_str_list *node);

#endif
