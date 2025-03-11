#include "loop.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

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

/// # ノンデバイスモード
///
/// ```bash
/// < bash.sh cat | ./minishell
/// ```
///
/// ```bash
/// ./minishell bash.sh
/// ```
///
/// ```bash
/// < bash.sh cat | ./minishell bash2.sh
/// ```
/// 
/// # デバイスモード(プロンプトを表示して、ユーザの入力を待機する)
///
/// ```bash
/// ./minishell
/// ```
int main(int argc, char *argv[], char *envp[])
{
	int fd;
	int exit_status;

	fd = -1;
	if (1 < argc)
	{
		fd = open(argv[1], O_RDONLY, 0644);
		if (fd == -1)
		{
			perror("minishell");
			return (1);
		}
		dup2(fd, STDIN_FILENO);
	}
	if (isatty(STDIN_FILENO))
	{
		header();
		exit_status = main_loop(envp);
	}
	else
		exit_status = none_device_main_loop(envp);
	if (fd != -1)
		close(fd);
	dprintf(STDERR_FILENO,"exit status %d\n", exit_status);
	return (exit_status);
}
