((< minishell cat  | sha256sum)  | awk '{print $1}' > outfile1) && ((sha256sum minishell | awk '{print $1}') > outfile2) && diff -u outfile1 outfile2 | wc -l
