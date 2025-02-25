#include "libft.h"
#include <stdbool.h>

/// 環境変数として使用可能な文字かどうかを判別する
/// 
/// a-zA-Z0-9
/// アンダースコア(_)
/// 
bool is_valid_env_char(char c)
{
	return (\
		ft_isalpha(c) ||\
		ft_isdigit(c) ||\
		'_' == c
	);
}

