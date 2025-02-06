#include <stdbool.h>

/// 環境変数として使用可能な文字かどうかを判別する
/// 
/// a-zA-Z0-9
/// アンダースコア(_)
/// 
bool is_valid_env_char(char c)
{
	return (\
		('a' <= c && c <= 'z') || \
		('A' <= c && c <= 'Z') || \
		('0' <= c && c <= '9') || \
		('_' == c)
	);
}

