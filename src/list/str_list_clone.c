#include "list.h"
#include <stdlib.h>


/// 第二引数で、どのレベルで、cloneするのかを決定できる
///
/// ## リストとともに中身の文字列もコピーして新しいものを用意したい場合
///
/// ```c
/// #include "libft.h"
/// str_list_clone(a, ft_strdup);
/// ```
///
/// ## 中身の文字列のアドレスはそのままリストだけ新しいものを用意したい場合
///
/// ```c
/// char *f(char *a){
///	 return (a);
/// }
/// str_list_clone(a, f);
/// ```
t_str_list *str_list_clone(t_str_list *a, char *(*f)(char *))
{
	t_str_list *rl;

	rl = NULL;
	while (a != NULL)
	{
		str_list_push(&rl, f(a->ptr.str));
		a = a->next;
	}
	return (rl);
}
