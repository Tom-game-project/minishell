<< EOF cat > infile 
hello world
This is Tom
EOF
touch outfile
< infile cat | cat > outfile
echo "$PATH"$PATH'$PATH' >> infile
echo "$PATH"'$PATH'$PATH >> infile
echo '$PATH'$PATH"$PATH" >> infile
echo "$PATH"$PATH'$PATH' >> outfile
echo "$PATH"'$PATH'$PATH >> outfile
echo '$PATH'$PATH"$PATH" >> outfile
diff infile outfile

