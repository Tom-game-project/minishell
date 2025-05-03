/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:49:38 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/01 19:50:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "loop.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// ビルド情報の取得
#define COMMIT_HASH
#define BUILD_TIMESTAMP
#define CC_VERSION

#ifdef DEBUG
# define MODE "mode: debug"
#else
# define MODE "mode: release"
#endif

int	header(void)
{
	ft_putstr_fd("        :::   :::   ::::::::::: ::::    ::: :::::::::::\n"
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
					"minishell(" COMMIT_HASH ", " MODE ", " BUILD_TIMESTAMP ")"
					"[" CC_VERSION "]\n",
					STDOUT_FILENO);
	return (0);
}

static int	set_none_device_stdin(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
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
int	main(int argc, char *argv[], char *envp[])
{
	int	exit_status;

	if (1 < argc)
	{
		if (set_none_device_stdin(argv[1]) == 1)
			return (1);
	}
	if (isatty(STDIN_FILENO))
	{
		header();
		exit_status = main_loop(envp);
	}
	else
		exit_status = none_device_main_loop(envp);
	return (exit_status);
}
