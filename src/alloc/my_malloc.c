#include <stdlib.h>
#include <unistd.h>
#include "libft.h"


/// __real_malloc は、元の malloc へリンク時にマッピングされる
void	*__real_malloc(size_t size);

/// リンク時にmallocが置き換えられる
/// このmalloc関数は、allocationに失敗すると、直ちにexitをする。
void	*__wrap_malloc(size_t size)
{
	void *ptr;

	ptr = __real_malloc(size);
	if (ptr == NULL)
	{
		ft_putstr_fd("allocation error occured\n", STDERR_FILENO);
		exit(1);
	}
	return (ptr);
}
