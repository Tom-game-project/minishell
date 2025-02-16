#include <stdio.h>
//#include "minishell.h"


# ifndef COMMIT_HASH
#  define COMMIT_HASH unknown
# endif


// 文字列展開用のマクロ
#define EXPAND(x) #x
#define STRINGER(x) EXPAND(x)

// int main(int argc, char *argv[], char *envp[])
// {
// 	int exit_status;

// 	exit_status = minishell(argc, argv, envp);
// 	return (exit_status);
// }

// int minishell(int argc, char *argv[], char *envp[])
// {

// }
//

int header()
{
	printf(
	""
"        :::   :::   ::::::::::: ::::    ::: :::::::::::\n"
"      :+:+: :+:+:      :+:     :+:+:   :+:     :+:     \n" 
"    +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+      \n" 
"   +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+       \n" 
"  +#+       +#+     +#+     +#+  +#+#+#     +#+        \n" 
" #+#       #+#     #+#     #+#   #+#+#     #+#         \n" 
"###       ### ########### ###    #### ###########      \n" 
"      ::::::::  :::    ::: :::::::::: :::        :::   \n"
"    :+:    :+: :+:    :+: :+:        :+:        :+:    \n"
"   +:+        +:+    +:+ +:+        +:+        +:+     \n"
"  +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+      \n"
"        +#+ +#+    +#+ +#+        +#+        +#+       \n"
"#+#    #+# #+#    #+# #+#        #+#        #+#        \n"
"########  ###    ### ########## ########## ##########  \n"
"            created by kaara && Tom in 2025            \n"
"commit hash: " STRINGER(COMMIT_HASH) "\n"
	); 
	// TODO: 
	// - バージョン番号
	// - コミットハッシュ DONE
	// - ビルドした時間
	// - ビルド環境の表示
	return (0);
}



#include <stdio.h>
int main()
{
	//
	//
	header();
	return (0); 
}
