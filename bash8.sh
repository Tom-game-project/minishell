echo ./../minishell/src/ex*/ex*.c | awk '{for(i=1;i<=NF;i++) printf "%d:%s ", i, $i; print ""}' | tr ' ' '\n'
echo ./src/ex*/ex*.c | awk '{for(i=1;i<=NF;i++) printf "%d:%s ", i, $i; print ""}' | tr ' ' '\n'
echo src/ex*/ex*.c | awk '{for(i=1;i<=NF;i++) printf "%d:%s ", i, $i; print ""}' | tr ' ' '\n'
echo bash*.sh | awk '{for(i=1;i<=NF;i++) printf "%d:%s ", i, $i; print ""}' | tr ' ' '\n'
