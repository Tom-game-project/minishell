#include "loop.h"
#include <stdio.h>

//#include "minishell.h"

// ビルド情報の取得
# ifndef COMMIT_HASH
#  define COMMIT_HASH unknown
# endif
# ifndef BUILD_TIMESTAMP
#  define BUILD_TIMESTAMP unknown
# endif
# ifndef CC_VERSION
#  define CC_VERSION unknown
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
"created by arakan && Tom in 2025                        \n"
"minishell("STRINGER(COMMIT_HASH)", "
STRINGER(BUILD_TIMESTAMP)")"
"["STRINGER(CC_VERSION)"]\n"); 
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	//
	header();
	main_loop(envp);
	return (0); 
}
