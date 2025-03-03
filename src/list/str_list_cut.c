#include "list.h"

/// リストを任意のindexでに分割する関数
///
/// def 
/// &lst = 
/// [0] -> [1] -> [2] -> [3] -> ...
///
/// 例えば、引数が
/// &lst
/// index = 2
/// のとき
/// 与えられたlstの新しい先頭は[3]となる
/// 切り取られた前側のリストの先頭が返り値となる
///
/// 関数実行後のlstの状態
/// &lst = [3] -> ...
///
/// return [0] -> [1] -> [2] -> NULL
t_str_list *
str_list_cut(t_str_list **node, int index)
{
	return (void_list_cut(node, index));
}
